/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   define_cheapest_route.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 18:31:13 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/02 13:44:48 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Calculates the nr of required UPWARD rotations in the destination stack
for the node to fit in the stack.
considers 2 cases:
- normal case: next larger then previous
- smallest item is on top of the stack
*/
static size_t	get_rotation_distance_up(t_stack *stack, t_stack *node)
{
	size_t	rotation_distance;
	t_stack	*next;
	t_stack	*previous;

	rotation_distance = 0;
	next = stack;
	previous = stack->previous;
	while (true)
	{
		if (next->index > previous->index)
		{
			if (previous->index < node->index && node->index < next->index)
				return (rotation_distance);
		}
		if (next->index < previous->index)
		{
			if (previous->index < node->index || node->index < next->index)
				return (rotation_distance);
		}
		next = next->next;
		previous = previous->next;
		rotation_distance++;
	}
}

static void	set_price_and_route(t_route *route_data, size_t price,
	size_t route_enum)
{
	route_data->price = price;
	route_data->route_enum = route_enum;
}

static void	set_dest_and_source_location(t_route *route_data, size_t pos_in_a,
	size_t pos_in_b)
{
	route_data->pos_in_a = pos_in_a;
	route_data->pos_in_b = pos_in_b;
}

/*
Calculates price of a node, and sets 'cheapest_route' if node is cheaper than
the cheapest route so far.
4 options are considerd to calcualte the price
- 0: rotate a upwards; rotate b upwards
- 1: rotate a upwards; rotate b downwards
- 2: rotate a downwards; rotate b upwards
- 3: rotate a downwards; rotate b downwards
NOTE: pos_in_b is zero based index
*/
static void	update_cheapest_route(t_route *route_data, t_data *data,
	t_stack *node_b, size_t pos_in_b)
{
	size_t	price_option;
	size_t	rotation_dist_stack_a_up;
	size_t	rotation_dist_stack_a_down;
	size_t	initial_price;

	initial_price = route_data->price;
	rotation_dist_stack_a_up = get_rotation_distance_up(data->stack_a, node_b);
	rotation_dist_stack_a_down = route_data->len_a - rotation_dist_stack_a_up;
	price_option = ft_max(rotation_dist_stack_a_up, pos_in_b);
	if (price_option < route_data->price)
		set_price_and_route(route_data, price_option, 0);
	price_option = rotation_dist_stack_a_up + (route_data->len_b - pos_in_b - 1);
	if (price_option < route_data->price)
		set_price_and_route(route_data, price_option, 1);
	price_option = rotation_dist_stack_a_down + pos_in_b;
	if (price_option < route_data->price)
		set_price_and_route(route_data, price_option, 2);
	price_option = ft_max(rotation_dist_stack_a_down,
			(route_data->len_b - pos_in_b - 1));
	if (price_option < route_data->price)
		set_price_and_route(route_data, price_option, 3);
	if (route_data->price < initial_price)
		set_dest_and_source_location(route_data, rotation_dist_stack_a_up,
			pos_in_b);
}

/*
Consideres the price of the i-th node from the top and the bottom in stack b.
*/
void	define_cheapest_route(t_route *route_data, t_data *data)
{
	size_t	i;
	t_stack	*node_from_top;
	t_stack	*node_from_bottom;

	i = 0;
	node_from_top = data->stack_b;
	node_from_bottom = data->stack_b->previous;
	while (i < (route_data->len_b / 2) && i < route_data->price)
	{
		update_cheapest_route(route_data, data, node_from_top, i);
		update_cheapest_route(route_data, data, node_from_bottom,
			(route_data->len_b) - i - 1);
		node_from_top = node_from_top->next;
		node_from_bottom = node_from_bottom->previous;
		i++;
	}
}
