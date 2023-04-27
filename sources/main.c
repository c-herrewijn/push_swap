/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 11:40:56 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/27 19:32:55 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
validate number of argc
validate individual args, should be valid integers
i.e. within range [INT_MIN, INT_MAX]
*/
static bool	is_valid_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (false);
	while (i < argc)
	{
		if (ft_isinteger(argv[i]) == false)
			return (false);
		j = 1;
		while (j < i)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	exit_with_error(t_stack *stack_a, t_stack *stack_b)
{
	write(STDERR_FILENO, "Error\n", 6);
	free_nodes_in_stack(stack_a);
	free_nodes_in_stack(stack_b);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		**staying_numbers;
	size_t		nr_count;

	stack_a = NULL;
	stack_b = NULL;
	if (is_valid_input(argc, argv) == false)
		exit_with_error(stack_a, stack_b);
	if (argc == 2)
		exit(0);
	if (parse_input(argc, argv, &stack_a) < 0)
		exit_with_error(stack_a, stack_b);
	nr_count = argc - 1;
	normalize_input(stack_a);
	staying_numbers = get_staying_numbers(stack_a, nr_count);
	if (staying_numbers == NULL)
		exit_with_error(stack_a, stack_b);
	push_all_to_b(&stack_a, &stack_b, staying_numbers, nr_count);

	// debug
	// printf("str: %s\n", str_from_bfs_path(staying_numbers));
	puts("stack a:");
	print_stack(stack_a);
	puts("stack b:");
	print_stack(stack_b);
	
	free_nodes_in_stack(stack_a);
	free_nodes_in_stack(stack_b);
	free(staying_numbers);
}
