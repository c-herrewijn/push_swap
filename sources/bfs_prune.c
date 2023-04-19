/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_prune.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 11:18:53 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/19 16:29:15 by cherrewi      ########   odam.nl         */
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
/  return 'true' means that the range of path2 fully covers the range of path1
/  this also implies that path2 can be removed
*/
static bool	paths_overlap(t_stack **path1, t_stack **path2)
{
	size_t	p1_start;
	size_t	p1_end;
	size_t	p2_start;
	size_t	p2_end;

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

/* compare paths with equal length, prune those with:
/  equal or worse start AND 
/  equal or worse end AND 
*/
static void	prune_paths_with_len(t_stack ***all_paths, size_t len)
{
	int		i;
	int		j;
	bool	prune_path_i;

	i = 0;
	while (all_paths[i] != NULL)
	{
		if (path_get_length(all_paths[i]) == len)
		{			
			j = 0;
			while (all_paths[j] != NULL)
			{
				if (i != j && path_get_length(all_paths[j]) == len)
				{
					if (paths_overlap(all_paths[j], all_paths[i]))
					{
						prune_path_i = true;
						break ;
					}	
				}
				j++;
			}
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

void	prune_sub_optimal_paths(t_stack ***all_paths)
{
	size_t	max_len;
	size_t	len;
	size_t	path_len;
	int		i;

	if (all_paths == NULL)
		return ;
	max_len = 0;
	i = 0;
	while (all_paths[i] != NULL)
	{
		path_len = path_get_length(all_paths[i]);
		if (path_len > max_len)
			max_len = path_len;
		i++;
	}
	len = 2;
	while (len < max_len)
	{
		prune_paths_with_len(all_paths, len);
		len++;
	}
}
