/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 11:41:20 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/21 13:37:26 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <assert.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	size_t			index;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

// parsing
int		parse_input(int argc, char *argv[], t_stack **stack_a);
void	normalize_input(t_stack *stack);

// operations
void	push(t_stack **push_to_stack, t_stack **take_from_stack);
void	swap(t_stack **stack);
void	rotate(t_stack **stack, char c);

// breadth first search
t_stack	**get_staying_numbers(t_stack *stack_a, size_t nr_count);
t_stack	**add_new_path(t_stack ***all_paths, size_t nr_count);
void	add_node_to_path(t_stack **path, t_stack *node);
int		duplicate_path(t_stack ***all_paths, t_stack **path_to_copy,
			size_t nr_count);
bool	can_be_added_to_path(t_stack **path, t_stack *node);
t_stack	**best_path_for_node(t_stack **path1, t_stack **path2,
			t_stack *node);
void	free_bfs_paths(t_stack ***all_paths, t_stack **best_path);
t_stack	**clean_and_select_best_path(t_stack ***all_paths);
size_t	nr_of_paths(t_stack ***all_paths);
size_t	path_get_length(t_stack **path);
size_t	path_get_last_index(t_stack **path);
size_t	path_get_first_index(t_stack **path);
void	remove_path(t_stack ***all_paths, t_stack **path);
void	prune_sub_optimal_paths(t_stack ***all_paths);

// stack utils
t_stack	*stack_get_last(t_stack *stack);
void	free_nodes_in_stack(t_stack *stack);

// debug
void	print_stack(t_stack *stack);
char	*str_from_stack(t_stack *stack);
char	*str_from_bfs_path(t_stack **path);
void	print_bfs_path(t_stack **path);
void	print_all_bfs_paths(t_stack ***all_paths);

#endif
