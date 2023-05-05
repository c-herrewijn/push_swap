/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sets.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 16:23:50 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/05 13:01:20 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_get_smallest(t_stack *stack)
{
	t_stack	*first;
	size_t	smallest;

	first = stack;
	smallest = stack->index;
	while (true)
	{
		smallest = ft_min(smallest, stack->index);
		stack = stack->next;
		if (stack == first)
			break ;
	}
	return (smallest);
}

size_t	stack_get_largest(t_stack *stack)
{
	t_stack	*first;
	size_t	largest;

	first = stack;
	largest = stack->index;
	while (true)
	{
		largest = ft_max(largest, stack->index);
		stack = stack->next;
		if (stack == first)
			break ;
	}
	return (largest);
}

// not all index numbers need to be present
bool	stack_is_circularly_ordered(t_stack *stack, size_t smallest,
	size_t largest)
{
	t_stack	*first;
	bool	second_part;

	first = stack;
	second_part = false;
	while (true)
	{
		if (second_part == true && stack->index > first->index)
			return (false);
		if (stack->index == largest)
		{
			if (stack->next->index != smallest)
				return (false);
			second_part = true;
		}
		else
			if (stack->index > stack->next->index)
				return (false);
		if (stack->next == first)
			break ;
		stack = stack->next;
	}
	return (true);
}

void	small_nr_sort(t_data *data)
{
	size_t	smallest;
	size_t	largest;

	smallest = stack_get_smallest(data->stack_a);
	largest = stack_get_largest(data->stack_a);
	while (stack_is_circularly_ordered(data->stack_a, smallest, largest)
		== false)
	{
		if (stack_len(data->stack_a) == 3)
		{
			execute_operation(data, "sa");
			break ;
		}
		else
		{
			execute_operation(data, "pb");
			smallest = stack_get_smallest(data->stack_a);
			largest = stack_get_largest(data->stack_a);
		}
	}
	push_back_to_a(data);
	rotate_stack_a_smallest_to_top(data);
}
