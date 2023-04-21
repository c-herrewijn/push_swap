/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_cleanup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 13:08:17 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/21 13:15:29 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// frees all paths, exept the best path
void	free_bfs_paths(t_stack ***all_paths, t_stack **best_path)
{
	int	i;

	i = 0;
	while (all_paths[i] != NULL)
	{
		if (all_paths[i] != best_path)
			free(all_paths[i]);
		i++;
	}
	free(all_paths);
}

// select first path with max length
t_stack	**clean_and_select_best_path(t_stack ***all_paths)
{
	size_t	len;
	size_t	max_len;
	int		i;
	int		i_win;
	t_stack	**best_path;

	len = 0;
	max_len = 0;
	i = 0;
	i_win = 0;
	while (all_paths[i] != NULL)
	{
		len = path_get_length(all_paths[i]);
		if (len > max_len)
		{
			max_len = len;
			i_win = i;
		}
		i++;
	}
	best_path = all_paths[i_win];
	free_bfs_paths(all_paths, best_path);
	return (best_path);
}
