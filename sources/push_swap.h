/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 11:41:20 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/18 16:27:34 by cherrewi      ########   odam.nl         */
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

// utils
bool	ft_isinteger(char *int_str);
t_stack	*stack_get_last(t_stack *stack);

// algo
t_stack	**get_staying_numbers(t_stack *stack_a, size_t nr_count);
t_stack	**add_new_path(t_stack ***all_paths, size_t nr_count);
void	add_node_to_path(t_stack **path, t_stack *node);
void	duplicate_path(t_stack ***all_paths, t_stack **path_to_copy, size_t nr_count);
size_t	path_get_length(t_stack **path);
bool	can_be_added_to_path(t_stack **path, t_stack *node);
t_stack	**best_path_to_add_node(t_stack **path1, t_stack **path2,
	t_stack *node);

// debug
void	print_stack(t_stack *stack);
char	*str_from_stack(t_stack *stack);
char	*str_from_bfs_path(t_stack **path);
void	print_bfs_path(t_stack **path);
void	print_all_bfs_paths(t_stack ***all_paths);
	


#endif
