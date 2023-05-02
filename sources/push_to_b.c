/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_to_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 15:09:40 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/02 16:24:56 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	index_in_range(size_t index, size_t lower_bound, size_t upper_bound)
{
	return (index <= upper_bound && index >= lower_bound);
}

/* 
Calculate the number of rotations needed for the stack to get to a state 
where it can receive a number in range [group_bottom - group_top].
Valid states of stack:
- all members of the stack are NOT within the range 
  (no rotation needed, we start the range)
  - this include scenarios where the stack has zero or 1 members
- OR bottom or top value of the stack is within the range
Return value: positive number is up, negative number is down
*/
static int	get_rotation_distance_grp(t_stack *stack, size_t group_bottom,
	size_t group_top)
{
	int		i;
	t_stack	*front_node;
	t_stack	*end_node;

	if (stack == NULL)
		return (0);
	i = 0;
	front_node = stack;
	end_node = stack->previous;
	while (true)
	{
		if (index_in_range(front_node->index, group_bottom, group_top))
			return (i);
		if (index_in_range(end_node->index, group_bottom, group_top))
			return (i * -1);
		front_node = front_node->next;
		end_node = end_node->previous;
		if (front_node == stack)
			return (0);
		i++;
	}
}

static void	rotate_b(t_data *data, int rotation_distance)
{
	if (rotation_distance < 0)
	{
		while (rotation_distance < 0)
		{
			execute_operation(data, "rrb");
			rotation_distance++;
		}
	}
	if (rotation_distance > 0)
	{
		while (rotation_distance > 0)
		{
			execute_operation(data, "rb");
			rotation_distance--;
		}
	}
}

// rotation_distance: positive number is up, negative number is down
static void	initial_push_to_b(t_data *data)
{
	int		rotation_distance;
	size_t	group_1_start;
	size_t	group_1_end;
	size_t	group_2_start;
	size_t	group_2_end;

	group_1_start = 0;
	group_1_end = (data->nr_count / 2) - 1;
	group_2_start = data->nr_count / 2;
	group_2_end = data->nr_count - 1;
	if (data->stack_a->index <= group_1_end)
		rotation_distance = get_rotation_distance_grp(data->stack_b,
				group_1_start, group_1_end);
	else
		rotation_distance = get_rotation_distance_grp(data->stack_b,
				group_2_start, group_2_end);
	rotate_b(data, rotation_distance);
	execute_operation(data, "pb");
}

void	push_all_to_b(t_data *data)
{
	t_stack	*first_rotated_node;
	size_t	nr_of_staying_numbers;

	nr_of_staying_numbers = path_get_length(data->staying_numbers);
	first_rotated_node = NULL;
	while (data->stack_a != NULL
		&& stack_len(data->stack_a) > nr_of_staying_numbers)
	{
		if (node_in_path(data->stack_a, data->staying_numbers))
		{
			if (first_rotated_node == NULL)
				first_rotated_node = data->stack_a;
			execute_operation(data, "ra");
		}
		else
			initial_push_to_b(data);
		if (data->stack_a == first_rotated_node)
			break ;
	}
}
