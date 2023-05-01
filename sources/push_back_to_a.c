/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_back_to_a.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 15:10:48 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/01 22:51:18 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	push_back_to_a(t_data *data)
{
	t_route route_data;

	// WHILE (keep looping till everyting in b is pushed to a)
	route_data.price = INT_MAX;
	route_data.len_a = stack_len(data->stack_a);;  // NOTE increment len_a in while loop!
	route_data.len_b = stack_len(data->stack_b);;  // NOTE decrement len_b in while loop!
	define_cheapest_route(&route_data, data);

	// execute_cheapest_route(&route_data, data);
		// 	execute_operation(stack_a, stack_b, "pa");

	// route_data.len_a += 1;
	// route_data.len_b -= 1;


	// ENDWHILE

	printf("cheapest route (pos_in_a): %zu\n", route_data.pos_in_a);
	printf("cheapest route (pos_in_b): %zu\n", route_data.pos_in_b);
	printf("cheapest route (len_a): %zu\n", route_data.len_a);
	printf("cheapest route (len_b): %zu\n", route_data.len_b);
	printf("cheapest route (price): %zu\n", route_data.price);
	printf("cheapest route (route_enum): %zu\n", route_data.route_enum);
}
