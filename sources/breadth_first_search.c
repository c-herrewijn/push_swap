/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   breadth_first_search.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 20:35:49 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/28 14:09:15 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds best path with specific length and adds the node to it
static int	add_node_to_existing_path_with_len(t_stack ***all_paths,
			t_stack *node, size_t nr_count, size_t len)
{
	int		i;
	t_stack	**best_path;

	i = 0;
	best_path = NULL;
	while (all_paths[i] != NULL)
	{
		if ((path_get_length(all_paths[i]) == len)
			&& can_be_added_to_path(all_paths[i], node))
		{
			best_path = best_path_for_node(best_path, all_paths[i], node);
		}
		i++;
	}
	if (best_path != NULL)
	{
		if (nr_of_paths(all_paths) < ((nr_count * nr_count + nr_count) / 2)
			&& path_get_last_index(best_path) + 1 != node->index
			&& duplicate_path(all_paths, best_path, nr_count) < 0)
			return (-1);
		add_node_to_path(best_path, node);
	}
	return (0);
}

static int	add_node_to_existing_paths(t_stack ***all_paths, t_stack *node,
				size_t nr_count)
{
	size_t	len;

	len = 0;
	while (len < nr_count)
	{
		if (add_node_to_existing_path_with_len(all_paths, node,
				nr_count, len) < 0)
			return (-1);
		len++;
	}
	return (0);
}

static int	create_new_path_for_node(t_stack ***all_paths, t_stack *node,
	size_t nr_count)
{
	t_stack	**new_path;

	if (node->previous != NULL && node->previous->index + 1 == node->index
		&& *all_paths != NULL)
		return (0);
	new_path = NULL;
	if (nr_of_paths(all_paths) < ((nr_count * nr_count + nr_count) / 2))
	{
		new_path = add_new_path(all_paths, nr_count);
		if (new_path == NULL)
			return (-1);
		add_node_to_path(new_path, node);
	}
	return (0);
}

/*
returns a list with numbers that remain in stack a
assumes stack_a is circular
max value for all_paths = (n^2 + n) / 2, which happens when the numbers are
already ordered
malloc size has one additional space for the terminating null pointer
*/
t_stack	**get_staying_numbers(t_stack *stack, size_t nr_count)
{
	t_stack	***all_paths;
	t_stack	*first;

	all_paths = ft_calloc(((nr_count * nr_count + nr_count) / 2 + 1),
			sizeof(t_stack **));
	if (all_paths == NULL)
		return (NULL);
	first = stack;
	while (true)
	{
		if (add_node_to_existing_paths(all_paths, stack, nr_count) < 0
			|| create_new_path_for_node(all_paths, stack, nr_count) < 0)
		{
			free_bfs_paths(all_paths, NULL);
			return (NULL);
		}
		stack = stack->next;
		if (stack == first)
			break ;
	}
	return (clean_and_select_best_path(all_paths));
}
