/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:43:44 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/15 21:56:57 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adjust_push_to_stack(t_stack **push_to_stack, t_stack *moving_item)
{
	if (*push_to_stack == NULL)
	{
		(moving_item)->next = moving_item;
		(moving_item)->previous = moving_item;
	}
	else
	{		
		(moving_item)->next = *push_to_stack;
		(moving_item)->previous = (*push_to_stack)->previous;
		(*push_to_stack)->previous->next = moving_item;
		(*push_to_stack)->previous = moving_item;
	}
	*push_to_stack = moving_item;
}

static void	adjust_take_from_stack(t_stack **take_from_stack,
	t_stack *temp_next, t_stack *temp_previous)
{
	if (temp_next == (*take_from_stack))
		*take_from_stack = NULL;
	else
	{
		temp_next->previous = temp_previous;
		temp_previous->next = temp_next;
		*take_from_stack = temp_next;
	}
}

void	push(t_stack **push_to_stack, t_stack **take_from_stack)
{
	t_stack	*temp_next;
	t_stack	*temp_previous;
	t_stack	*moving_item;

	if (push_to_stack == NULL || take_from_stack == NULL)
		return ;
	if (*take_from_stack == NULL)
		return ;
	moving_item = *take_from_stack;
	temp_next = moving_item->next;
	temp_previous = moving_item->previous;
	adjust_push_to_stack(push_to_stack, moving_item);
	adjust_take_from_stack(take_from_stack, temp_next, temp_previous);
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	last = first->previous;
	if (first->next->next != first)
	{		
		first->next = third;
		third->previous = first;
		second->next = first;
		first->previous = second;
		last->next = second;
		second->previous = last;
	}
	*stack = second;
}

/*
'n' for normal rotate
'r' for reverse rotate
*/
void	rotate(t_stack **stack, char c)
{
	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	if (c == 'n')
		*stack = (*stack)->next;
	if (c == 'r')
		*stack = (*stack)->previous;
}
