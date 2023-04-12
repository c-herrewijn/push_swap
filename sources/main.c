/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 11:40:56 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/12 16:26:18 by cherrewi      ########   odam.nl         */
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
	
	i = 1;
	if (argc < 2)
		return (false);
	while (i < argc)
	{
		if (ft_isinteger(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

// t_stack *parse_input(int argc, char *argv[])
// {
// 	t_stack *stack_a;

// 	stack_a = NULL;
// 	return (stack_a);
// }

int	main(int argc, char *argv[])
{
	t_stack *stack_a;  // points to the top of the stack
	t_stack *stack_b;  // points to the top of the stack

	if (is_valid_input(argc, argv) == false)
	{
		write(1, "Error\n", 6);
		exit(1);
	}

	// todo: parse input
	stack_a = NULL; // placeholder
	// stack_a = parse_input(argc, argv);
	// if (stack_a == NULL)
	// 	write(1, "Error\n", 6);

	// todo: check input: no duplicates
	// todo: normalize input
	// todo: sort algorithm
	stack_b = NULL;
	
	// dummy out:
	puts("pb");
	puts("sa");
	puts("ra");
	puts("pa");
}
