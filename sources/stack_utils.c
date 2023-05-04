/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:36:29 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/04 19:07:03 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
gets last item from a circular or a non circular linked list
*/
t_stack	*stack_get_last(t_stack *stack)
{
	t_stack	*stack_i;

	if (stack == NULL)
		return (NULL);
	stack_i = stack;
	while (stack_i->next != NULL && stack_i->next != stack)
	{
		stack_i = stack_i->next;
	}
	return (stack_i);
}

size_t	stack_len(t_stack *stack)
{
	t_stack	*stack_i;
	size_t	count;

	if (stack == NULL)
		return (0);
	count = 1;
	stack_i = stack;
	while (stack_i->next != NULL && stack_i->next != stack)
	{
		count++;
		stack_i = stack_i->next;
	}
	return (count);
}

/*
free nodes in stack (not the stack itself)
*/
void	free_nodes_in_stack(t_stack *stack)
{
	t_stack	*first;
	t_stack	*next;

	if (stack == NULL)
		return ;
	first = stack;
	while (true)
	{
		next = stack->next;
		free(stack);
		stack = next;
		if (stack == first)
			break ;
	}
}

/*
assumes the linked list is circular
*/
bool	stack_is_ordered(t_stack *stack)
{
	t_stack	*first;

	first = stack;
	while (true)
	{
		if (stack->next == first)
			break ;
		if (stack->index > stack->next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}
