/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 11:40:56 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/11 17:32:42 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data		data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	if (is_valid_input(argc, argv) == false)
		exit_with_error(data.stack_a, data.stack_b);
	if (parse_input(argc, argv, &(data.stack_a), &data) < 0)
		exit_with_error(data.stack_a, data.stack_b);
	normalize_input(data.stack_a);
	if (data.nr_count < 8)
		small_nr_sort(&data);
	else
	{
		data.staying_numbers = get_staying_numbers(&data);
		if (data.staying_numbers == NULL)
			exit_with_error(data.stack_a, data.stack_b);
		push_all_to_b(&data);
		free(data.staying_numbers);
		push_back_to_a(&data);
		rotate_stack_a_smallest_to_top(&data);
	}
	free_nodes_in_stack(data.stack_a);
}
