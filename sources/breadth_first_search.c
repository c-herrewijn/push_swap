/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   breadth_first_search.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 20:35:49 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/04 15:54:17 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds best path with specific length and adds the node to it
static int	add_node_to_existing_path_with_len(t_stack ***all_paths,
			t_stack *node, t_data *data, size_t len)
{
	int		i;
	t_stack	**best_path;
	size_t	max_nr_paths;

	max_nr_paths = (data->nr_count * data->nr_count + data->nr_count) / 2;
	i = 0;
	best_path = NULL;
	while (all_paths[i] != NULL)
	{
		if ((path_get_length(all_paths[i]) == len)
			&& can_be_added_to_path(all_paths[i], node))
		best_path = best_path_for_node(best_path, all_paths[i], node);
		i++;
	}
	if (best_path != NULL)
	{
		if (nr_of_paths(all_paths) < (max_nr_paths)
			&& path_get_last_index(best_path) + 1 != node->index
			&& duplicate_path(all_paths, best_path, data->nr_count) < 0)
			return (-1);
		add_node_to_path(best_path, node, data);
		compare_and_prune(all_paths, best_path);
	}
	return (0);
}

// static int	add_node_to_existing_paths(t_stack ***all_paths, t_stack *node,
// 				size_t nr_count, size_t *nr_staying_numbers)
static int	add_node_to_existing_paths(t_stack ***all_paths, t_stack *node,
	t_data *data)
{
	size_t	len;

	len = 0;
	while (len <= data->nr_staying_numbers)
	{
		if (add_node_to_existing_path_with_len(all_paths, node, data, len) < 0)
			return (-1);
		len++;
	}
	return (0);
}

static int	create_new_path_for_node(t_stack ***all_paths, t_stack *node,
	t_data *data)
{
	t_stack	**new_path;
	size_t	max_nr_paths;

	max_nr_paths = (data->nr_count * data->nr_count + data->nr_count) / 2;
	if (node->previous != NULL && node->previous->index + 1 == node->index
		&& *all_paths != NULL)
		return (0);
	new_path = NULL;
	if (nr_of_paths(all_paths) < max_nr_paths)
	{
		new_path = add_new_path(all_paths, data->nr_count);
		if (new_path == NULL)
			return (-1);
		add_node_to_path(new_path, node, data);
		if (data->nr_staying_numbers == 0)
			data->nr_staying_numbers = 1;
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
t_stack	**get_staying_numbers(t_data *data)
{
	t_stack	***all_paths;
	t_stack	*first;
	t_stack	*node_i;

	data->nr_staying_numbers = 0;
	all_paths = ft_calloc(((data->nr_count * data->nr_count
					+ data->nr_count) / 2 + 1), sizeof(t_stack **));
	if (all_paths == NULL)
		return (NULL);
	first = data->stack_a;
	node_i = data->stack_a;
	while (true)
	{
		if (add_node_to_existing_paths(all_paths, node_i, data) < 0
			|| create_new_path_for_node(all_paths, node_i, data) < 0)
		{
			free_bfs_paths(all_paths, NULL);
			return (NULL);
		}
		node_i = node_i->next;
		if (node_i == first)
			break ;
	}
	return (clean_and_select_best_path(all_paths));
}
