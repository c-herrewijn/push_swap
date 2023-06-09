/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_back_to_a.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 15:10:48 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/04 17:03:49 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a_smallest_to_top(t_data *data)
{
	size_t	first_node_pos;
	size_t	stack_length;
	t_stack	*node_i;
	size_t	i;

	first_node_pos = 0;
	stack_length = stack_len(data->stack_a);
	node_i = data->stack_a;
	while (node_i->index != 0)
	{
		first_node_pos++;
		node_i = node_i->next;
	}
	i = 0;
	if (first_node_pos <= stack_length / 2)
		execute_operation_n_times(data, "ra", first_node_pos);
	else
		execute_operation_n_times(data, "rra", stack_length - first_node_pos);
}

static void	execute_route_same_direction(t_route *route_data, t_data *data)
{
	size_t	pos_a;
	size_t	pos_b;
	size_t	nr_double_rotations;

	pos_a = route_data->pos_in_a;
	pos_b = route_data->pos_in_b;
	if (route_data->route_enum == 0)
	{
		nr_double_rotations = ft_min(pos_a, pos_b);
		execute_operation_n_times(data, "rr", nr_double_rotations);
		execute_operation_n_times(data, "ra", pos_a - nr_double_rotations);
		execute_operation_n_times(data, "rb", pos_b - nr_double_rotations);
	}
	if (route_data->route_enum == 3)
	{
		nr_double_rotations = ft_min(route_data->len_a
				- pos_a, route_data->len_b - pos_b);
		execute_operation_n_times(data, "rrr", nr_double_rotations);
		execute_operation_n_times(data, "rra",
			route_data->len_a - pos_a - nr_double_rotations);
		execute_operation_n_times(data, "rrb",
			route_data->len_b - pos_b - nr_double_rotations);
	}
}

static void	execute_route_opposing_direction(t_route *route_data, t_data *data)
{
	size_t	pos_a;
	size_t	pos_b;

	pos_a = route_data->pos_in_a;
	pos_b = route_data->pos_in_b;
	if (route_data->route_enum == 1)
	{
		execute_operation_n_times(data, "ra", pos_a);
		execute_operation_n_times(data, "rrb", route_data->len_b - pos_b);
	}
	if (route_data->route_enum == 2)
	{
		execute_operation_n_times(data, "rra", route_data->len_a - pos_a);
		execute_operation_n_times(data, "rb", pos_b);
	}
}

static void	execute_cheapest_route(t_route *route_data, t_data *data)
{
	if (route_data->route_enum == 0 || route_data->route_enum == 3)
		execute_route_same_direction(route_data, data);
	if (route_data->route_enum == 1 || route_data->route_enum == 2)
		execute_route_opposing_direction(route_data, data);
	execute_operation(data, "pa");
}

void	push_back_to_a(t_data *data)
{
	t_route	route_data;
	size_t	len_a;
	size_t	len_b;

	len_a = stack_len(data->stack_a);
	len_b = stack_len(data->stack_b);
	while (len_b > 0)
	{
		route_data.price = INT_MAX;
		route_data.len_a = len_a;
		route_data.len_b = len_b;
		define_cheapest_route(&route_data, data);
		execute_cheapest_route(&route_data, data);
		len_a++;
		len_b--;
	}
}
