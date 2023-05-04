/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_add_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 13:01:00 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/03 22:16:51 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**add_new_path(t_stack ***all_paths, size_t nr_count)
{
	int	i;

	i = 0;
	while (all_paths[i] != NULL)
		i++;
	all_paths[i] = ft_calloc(nr_count + 1, sizeof(t_stack *));
	if (all_paths[i] == NULL)
		return (NULL);
	return (all_paths[i]);
}

void	add_node_to_path(t_stack **path, t_stack *node, t_data *data)
{
	size_t	i;

	i = 0;
	while (path[i] != NULL)
		i++;
	path[i] = node;
	if (i + 1 > data->nr_staying_numbers)
		data->nr_staying_numbers = i + 1;
}

int	duplicate_path(t_stack ***all_paths, t_stack **path_to_copy,
	size_t nr_count)
{
	t_stack	**new_path;
	int		i;

	new_path = add_new_path(all_paths, nr_count);
	if (new_path == NULL)
		return (-1);
	i = 0;
	while (path_to_copy[i] != NULL)
	{
		new_path[i] = path_to_copy[i];
		i++;
	}
	return (0);
}

// checks if a node can be added to a path without breaking the circularity
// circularity means that every next item is larger than its direct predecessor,
// except for the smallest item, which might be at any location.
bool	can_be_added_to_path(t_stack **path, t_stack *node)
{
	size_t	first_index;
	size_t	last_index;
	size_t	i;

	if (node == NULL || path == NULL)
		return (false);
	if (*path == NULL)
		return (true);
	first_index = path[0]->index;
	i = 0;
	while (path[i] != NULL)
		i++;
	last_index = path[i - 1]->index;
	if (last_index >= first_index)
		return (node->index > last_index || node->index < first_index);
	else
		return (node->index > last_index && node->index < first_index);
}

/*
Assumptions:
- path1 and path2 have equal lengths
- the node fits at the end of both paths
LOGIC:
- the start of the path should preferably be smaller than the new node
  so if one is and one isnt't (XOR operator), path with the smallest start wins
- if both paths start indices are smaller or bigger than the new node, the
  path with the largest start wins
*/
t_stack	**best_path_for_node(t_stack **path1, t_stack **path2,
	t_stack *node)
{
	size_t	p1_first_index;
	size_t	p2_first_index;

	if (path1 == NULL && path2 != NULL)
		return (path2);
	if (path1 != NULL && path2 == NULL)
		return (path1);
	if (path1 == NULL && path2 == NULL)
		return (NULL);
	p1_first_index = path_get_first_index(path1);
	p2_first_index = path_get_first_index(path2);
	if ((p1_first_index < node->index) ^ (p2_first_index < node->index))
	{
		if (p1_first_index < p2_first_index)
			return (path1);
		else
			return (path2);
	}
	else
	{
		if (p1_first_index > p2_first_index)
			return (path1);
		else
			return (path2);
	}
}
