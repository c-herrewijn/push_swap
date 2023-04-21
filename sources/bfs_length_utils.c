/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_length_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 17:49:11 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/21 17:24:39 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	node_in_path(t_stack *node, t_stack **path)
{
	int	i;

	if (path == NULL || path[0] == NULL)
		return (false);
	i = 0;
	while (path[i] != NULL)
	{
		if (path[i] == node)
			return (true);
		i++;
	}
	return (false);
}

size_t	nr_of_paths(t_stack ***all_paths)
{
	size_t	i;

	if (all_paths == NULL)
		return (0);
	i = 0;
	while (all_paths[i] != NULL)
		i++;
	return (i);
}

size_t	path_get_length(t_stack **path)
{
	size_t	i;

	if (path == NULL)
		return (0);
	i = 0;
	while (path[i] != NULL)
		i++;
	return (i);
}

size_t	path_get_first_index(t_stack **path)
{
	return (path[0]->index);
}

size_t	path_get_last_index(t_stack **path)
{
	size_t	i;

	i = 0;
	while (path[i] != NULL)
		i++;
	return (path[i - 1]->index);
}
