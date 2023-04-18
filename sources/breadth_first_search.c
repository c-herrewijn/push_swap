/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   breadth_first_search.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 20:35:49 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/18 16:27:28 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node_to_existing_path_with_len(t_stack ***all_paths,
			t_stack *node, size_t nr_count, size_t len)
{
	int		i;
	t_stack	**best_path; // will contain the path to which the node will be added
	
	i = 0;
	best_path = NULL;
	while (all_paths[i] != NULL)
	{
		if ((path_get_length(all_paths[i]) == len)
			&& can_be_added_to_path(all_paths[i], node))
		{
			if (best_path == NULL)
				best_path = all_paths[i];
			else
				best_path = best_path_to_add_node(best_path, all_paths[i], node);
		}
		i++;
	}
	if (best_path != NULL)
	{		
		duplicate_path(all_paths, best_path, nr_count);
		add_node_to_path(best_path, node);
	}
}


static void	add_node_to_existing_paths(t_stack ***all_paths, t_stack *node, size_t nr_count)
{
	size_t	len;

	len = 0;

	while (len < nr_count)
	{
		add_node_to_existing_path_with_len(all_paths, node, nr_count, len);
		len++;
	}
}

// assumes stack_a is circular
t_stack	**get_staying_numbers(t_stack *stack, size_t nr_count)
{
	t_stack	***all_paths;
	t_stack	**new_path;
	t_stack	*first;

	all_paths = ft_calloc((nr_count * 10 + 100), sizeof(t_stack **));  // to decide: number of paths
	if (all_paths == NULL)
		return (NULL);
	first = stack;
	while (true)
	{
		add_node_to_existing_paths(all_paths, stack, nr_count);
		
		// add new path for just the new node -> TODO malloc error handling!
		new_path = add_new_path(all_paths, nr_count);
		add_node_to_path(new_path, stack);

		// TODO: prune sub-optimal lists;

		stack = stack->next;
		if (stack == first)
			break ;
	}
	puts("debug, temp results:");
	print_all_bfs_paths(all_paths);

	// TODO: select longest list
	return (NULL);
}
