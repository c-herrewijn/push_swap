/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_back_to_a.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 15:10:48 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/02 12:56:29 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cheapest_route(t_route *route_data, t_data *data)
{
	size_t	pos_a;
	size_t	pos_b;

	pos_a = route_data->pos_in_a;
	pos_b = route_data->pos_in_b;
	if (route_data->route_enum == 0)
	{
		while (pos_a > 0 || pos_b > 0)
		{
			if (pos_a > 0 && pos_b > 0)
			{
				execute_operation(&(data->stack_a), &(data->stack_b), "rr");
				pos_a--;
				pos_b--;
			}
			if (pos_a > 0 && pos_b == 0)
			{
				execute_operation(&(data->stack_a), &(data->stack_b), "ra");
				pos_a--;
			}
			if (pos_a == 0 && pos_b > 0)
			{
				execute_operation(&(data->stack_a), &(data->stack_b), "rb");
				pos_b--;
			}
		}
		execute_operation(&(data->stack_a), &(data->stack_b), "pa");
	}
			
	if (route_data->route_enum == 1)
	{
		while (pos_a > 0 || pos_b < route_data->len_b)
		{			
			if (pos_a > 0)
			{
				execute_operation(&(data->stack_a), &(data->stack_b), "ra");
				pos_a--;
			}
			if (pos_b < route_data->len_b)
			{
				execute_operation(&(data->stack_a), &(data->stack_b), "rrb");
				pos_b++;
			}
		}
		execute_operation(&(data->stack_a), &(data->stack_b), "pa");
	}

	if (route_data->route_enum == 2)
	{
		while (pos_a < route_data->len_a || pos_b > 0)
		{
			if (pos_a < route_data->len_a)
			{
				execute_operation(&(data->stack_a), &(data->stack_b), "rra");
				pos_a++;
			}
			if (pos_b > 0)
			{
				execute_operation(&(data->stack_a), &(data->stack_b), "rb");
				pos_b--;
			}
		}
		execute_operation(&(data->stack_a), &(data->stack_b), "pa");
	}

	if (route_data->route_enum == 3)
	{
		while (pos_a < route_data->len_a && pos_b < route_data->len_b)
		{
			execute_operation(&(data->stack_a), &(data->stack_b), "rrr");
			pos_a++;
			pos_b++;
		}
		while (pos_a < route_data->len_a)
		{
			execute_operation(&(data->stack_a), &(data->stack_b), "rra");
			pos_a++;
		}
		while (pos_b < route_data->len_b)
		{
			execute_operation(&(data->stack_a), &(data->stack_b), "rrb");
			pos_b++;
		}
		execute_operation(&(data->stack_a), &(data->stack_b), "pa");
	}
}

void	push_back_to_a(t_data *data)
{
	t_route route_data;
	size_t	len_a;
	size_t	len_b;

	// WHILE (keep looping till everyting in b is pushed to a)

	len_a = stack_len(data->stack_a);
	len_b = stack_len(data->stack_b);

	while (len_b > 0)
	{
		route_data.price = INT_MAX;
		route_data.len_a = len_a;
		route_data.len_b = len_b;
		define_cheapest_route(&route_data, data);
		// puts("---");
		// printf("pos_in_a: %zu\n", route_data.pos_in_a);
		// printf("pos_in_b: %zu\n", route_data.pos_in_b);
		// printf("len_a: %zu\n", route_data.len_a);
		// printf("len_b: %zu\n", route_data.len_b);
		// printf("price: %zu\n", route_data.price);
		// printf("route_enum: %zu\n", route_data.route_enum);

		execute_cheapest_route(&route_data, data);
		len_a++;
		len_b--;
	}

	// execute_cheapest_route(&route_data, data);
		// 	execute_operation(stack_a, stack_b, "pa");

	// route_data.len_a += 1;
	// route_data.len_b -= 1;


	// ENDWHILE

	// printf("cheapest route (pos_in_a): %zu\n", route_data.pos_in_a);
	// printf("cheapest route (pos_in_b): %zu\n", route_data.pos_in_b);
	// printf("cheapest route (len_a): %zu\n", route_data.len_a);
	// printf("cheapest route (len_b): %zu\n", route_data.len_b);
	// printf("cheapest route (price): %zu\n", route_data.price);
	// printf("cheapest route (route_enum): %zu\n", route_data.route_enum);
}
