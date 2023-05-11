/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validations.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 15:26:59 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/11 15:27:23 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
validate number of argc
validate individual args, should be valid integers
i.e. within range [INT_MIN, INT_MAX]
EXCEPTION: no validation takes place if only 1 argument is given (argc == 2)
(case argc == 2 is handled during parsing)
*/
bool	is_valid_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		exit(0);
	if (argc > 2)
	{
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
