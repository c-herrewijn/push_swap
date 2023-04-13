/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:36:29 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/13 16:50:22 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_get_last(t_stack *stack)
{
	t_stack	*stack_i;

	if (stack == NULL)
		return (NULL);
	stack_i = stack;
	while (stack_i->next && stack_i->next != stack)
	{
		stack_i = stack_i->next;
	}
	return (stack_i);
}
