/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_prune.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 11:18:53 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/20 16:09:51 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
free path, set path to NULL, move other paths after it upwards
*/
void	remove_path(t_stack ***all_paths, t_stack **path)
{
	int		i;
	bool	start_moving_tail_end;

	i = 0;
	start_moving_tail_end = false;
	while (all_paths[i] != NULL)
	{
		if (start_moving_tail_end == true)
		{
			all_paths[i - 1] = all_paths[i];
			all_paths[i] = NULL;
		}
		if (all_paths[i] == path)
		{
			free(all_paths[i]);
			all_paths[i] = NULL;
			start_moving_tail_end = true;
		}
		i++;
	}
}

/*
set node to NULL, move tail part upwards
no free required, because path only contains pointers
the actual node instance needs to be retained 
(we only remove it from the path, not from the stack)
*/
void	remove_node(t_stack **path, t_stack *node)
{
	int		i;
	bool	start_moving_tail_end;

	i = 0;
	start_moving_tail_end = false;
	while (path[i] != NULL)
	{
		if (start_moving_tail_end == true)
		{
			path[i - 1] = path[i];
			path[i] = NULL;
		}
		if (path[i] == node)
		{
			start_moving_tail_end = true;
			path[i] = NULL;
		}
		i++;
	}
}

/* compares path2 with path1
/  return 'true' means:
/   - path2 has fewer or equal nodes then path1
/   - AND the range of path2 fully covers the range of path1
/  this implies that path2 is inferior to path1
*/
static bool	paths_overlap(t_stack **path1, t_stack **path2)
{
	size_t	p1_start;
	size_t	p1_end;
	size_t	p2_start;
	size_t	p2_end;

	if (path_get_length(path1) < path_get_length(path2))
		return (false);
	p1_start = path_get_first_index(path1);
	p1_end = path_get_last_index(path1);
	p2_start = path_get_first_index(path2);
	p2_end = path_get_last_index(path2);
	if (p1_start < p1_end && p2_start < p2_end
		&& (p2_start <= p1_start && p2_end >= p1_end))
		return (true);
	if (p1_start < p1_end && p2_start > p2_end
		&& (p2_start <= p1_start || p2_end >= p1_end))
		return (true);
	if (p1_start > p1_end && p2_start > p2_end
		&& (p2_start <= p1_start && p2_end >= p1_end))
		return (true);
	return (false);
}

/* prunes unpromising paths
/  based on pairwise comparison on start-end range and amount of nodes
/  paths with worse start-end range and equal or fewer nodes are pruned
*/
void	prune_sub_optimal_paths(t_stack ***all_paths)
{
	int		i;
	int		j;
	bool	prune_path_i;

	i = 0;
	while (all_paths[i] != NULL)
	{
		j = 0;
		while (all_paths[j] != NULL)
		{
			if (i != j && paths_overlap(all_paths[j], all_paths[i]))
			{
				prune_path_i = true;
				break ;
			}	
			j++;
		}
		if (prune_path_i == true)
		{
			remove_path(all_paths, all_paths[i]);
			prune_path_i = false;
		}
		else
			i++;
	}
}
