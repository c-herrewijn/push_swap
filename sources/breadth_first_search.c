/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   breadth_first_search.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 20:35:49 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/17 21:09:00 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**add_new_path(t_stack ***all_paths, size_t nr_count)
{
	int	i;

	i = 0;
	while (all_paths[i] != NULL)
		i++;
	all_paths[i] = ft_calloc(nr_count + 100, sizeof(t_stack *));  // should be nr_count + 1
	if (*all_paths == NULL)
	{
		puts("error");
		return (NULL);
	}
	return (all_paths[i]);
}

void	add_node_to_path(t_stack **path, t_stack *node)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
		i++;
	path[i] = node;
}

void	copy_path(t_stack ***all_paths, t_stack **path_to_copy, size_t nr_count)
{
	t_stack	**new_path;
	int		i;

	new_path = add_new_path(all_paths, nr_count);
	i = 0;
	while (path_to_copy[i] != NULL)
	{
		new_path[i] = path_to_copy[i];
		i++;
	}
}

void	update_bfs_paths(t_stack ***all_paths, t_stack *stack, size_t nr_count)
{
	int		i;
	t_stack	**new_path;

	i = 0;
	while (all_paths[i] != NULL)
	{

		// todo: only add node to list if rotable
		add_node_to_path(all_paths[i], stack);

		i++;
	}
	
	// create new list with node
	new_path = add_new_path(all_paths, nr_count);
	new_path[0] = stack;
}

// assumes stack_a is circular
t_stack	**get_staying_numbers(t_stack *stack, size_t nr_count)
{
	t_stack	***all_paths;
	t_stack	*first;

	all_paths = ft_calloc((nr_count * 10 + 100), sizeof(t_stack **));  // to decide: number of paths
	if (all_paths == NULL)
		return (NULL);
	first = stack;
	while (true)
	{
		update_bfs_paths(all_paths, stack, nr_count);
		stack = stack->next;
		if (stack == first)
			break ;
	}
	// TODO: select longest list
	return (NULL);
}
