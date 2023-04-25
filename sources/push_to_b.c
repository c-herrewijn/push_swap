/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_to_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 15:09:40 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/25 16:54:15 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **stack_a, t_stack **stack_b,
						t_stack **staying_numbers)
{
	t_stack	*first_rotated_node;
	size_t	nr_of_staying_numbers;

	nr_of_staying_numbers = path_get_length(staying_numbers);
	first_rotated_node = NULL;
	while (*stack_a != NULL && stack_len(*stack_a) > nr_of_staying_numbers)
	{
		if (node_in_path(*stack_a, staying_numbers))
		{
			if (first_rotated_node == NULL)
				first_rotated_node = *stack_a;
			execute_operation(stack_a, stack_b, "ra");
		}
		else
			execute_operation(stack_a, stack_b, "pb");
		if (*stack_a == first_rotated_node)
			break ;
	}
}
