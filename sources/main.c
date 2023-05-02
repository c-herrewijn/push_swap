/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 11:40:56 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/02 15:49:41 by cherrewi      ########   odam.nl         */
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
	t_data		data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	if (is_valid_input(argc, argv) == false)
		exit_with_error(data.stack_a, data.stack_b);
	if (argc == 2)
		exit(0);
	if (parse_input(argc, argv, &(data.stack_a)) < 0)
		exit_with_error(data.stack_a, data.stack_b);
	data.nr_count = argc - 1;
	normalize_input(data.stack_a);
	data.staying_numbers = get_staying_numbers(data.stack_a, data.nr_count);
	if (data.staying_numbers == NULL)
		exit_with_error(data.stack_a, data.stack_b);
	push_all_to_b(&data);
	push_back_to_a(&data);
	rotate_stack_a_smallest_to_top(&data);
	free_nodes_in_stack(data.stack_a);
	free_nodes_in_stack(data.stack_b);
	free(data.staying_numbers);
}
