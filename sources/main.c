/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 11:40:56 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/13 19:54:46 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
validate number of argc
validate individual args, should be valid integers
i.e. within range [INT_MIN, INT_MAX]
*/
bool	is_valid_input(int argc, char *argv[])
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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;  // points to the top of the stack
	t_stack	*stack_b;  // points to the top of the stack

	stack_a = NULL;
	stack_b = NULL;
	if (is_valid_input(argc, argv) == false)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(1);
	}
	if (parse_input(argc, argv, &stack_a) < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(1);
	}
	normalize_input(stack_a);


	// debug
	// int a = 0;
	// t_stack	*record = stack_a;
	// printf("value: %d - index: %d\n", record->value, record->index);
	// record = record->next;
	// while (record != stack_a)
	// {
	// 	printf("value: %d - index: %d\n", record->value, record->index);
	// 	record = record->next;
	// 	a++;
	// }

	// todo: sort algorithm


	
	// dummy out:
	puts("pb");
	puts("sa");
	puts("ra");
	puts("pa");
}
