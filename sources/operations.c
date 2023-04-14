/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:43:44 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/14 17:10:09 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to(t_stack **push_to_stack, t_stack **take_from_stack)
{
	t_stack *temp_next;
	t_stack *temp_previous;
	
	if (push_to_stack == NULL || take_from_stack == NULL)
		return ;
	if (*take_from_stack == NULL)
		return ;
	temp_next = (*take_from_stack)->next;
	temp_previous = (*take_from_stack)->previous;

	// cases: 
	// push to stack empty
	// take from stack empty

	// adjusting push-to stack
	if (*push_to_stack == NULL)
	{
		(*take_from_stack)->next = *take_from_stack;
		(*take_from_stack)->previous = *take_from_stack;
	}
	else
	{		
		(*take_from_stack)->next = *push_to_stack;
		(*take_from_stack)->previous = (*push_to_stack)->previous;
		(*push_to_stack)->previous->next = *take_from_stack;
		(*push_to_stack)->previous = *take_from_stack;
	}
	*push_to_stack = *take_from_stack;
	
	// adjusting take from stack
	if (temp_next == (*take_from_stack))
		*take_from_stack = NULL;
	else
	{
		temp_next->previous = temp_previous;
		temp_previous->next = temp_next;
		*take_from_stack = temp_next;
	}
}

void swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;
	t_stack *last;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	last = first->previous;
	first->next = third;
	third->previous = first;
	second->next = first;
	first->previous = second;
	last->next = second;
	second->previous = last;
	*stack = second;
}

void rotate(t_stack **stack)
{
	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
}

void reverse_rotate(t_stack **stack)
{
	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	*stack = (*stack)->previous;
}

