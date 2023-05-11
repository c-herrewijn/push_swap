/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 11:41:20 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/11 16:52:03 by cherrewi      ########   odam.nl         */
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
# include <time.h>

typedef struct s_stack
{
	int				value;
	size_t			index;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

typedef struct s_route
{
	size_t	pos_in_a;
	size_t	pos_in_b;
	size_t	len_a;
	size_t	len_b;
	size_t	price;
	size_t	route_enum;
}	t_route;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	**staying_numbers;
	size_t	nr_count;
	size_t	nr_staying_numbers;
}	t_data;

// parsing
int			parse_input(int argc, char *argv[], t_stack **stack_a,
				t_data *data);
bool		is_valid_input(int argc, char *argv[]);
int			validate_and_parse_spaced_numbers(char *str, t_stack **stack_a,
				t_data *data);
int			add_new_to_stack(int num, t_stack **stack);
void		normalize_input(t_stack *stack);
void		exit_with_error(t_stack *stack_a, t_stack *stack_b);

// operations
void		push(t_stack **push_to_stack, t_stack **take_from_stack);
void		swap(t_stack **stack);
void		rotate(t_stack **stack, char c);
void		execute_push(t_stack **stack_a, t_stack **stack_b, char *command);
void		execute_swap(t_stack **stack_a, t_stack **stack_b, char *command);
void		execute_rotate(t_stack **stack_a, t_stack **stack_b,
				char *command);
void		execute_operation(t_data *data, char *command);
void		execute_operation_n_times(t_data *data,	char *command, size_t n);

// breadth first search
t_stack		**get_staying_numbers(t_data *data);
t_stack		**add_new_path(t_stack ***all_paths, size_t nr_count);
void		add_node_to_path(t_stack **path, t_stack *node, t_data *data);
int			duplicate_path(t_stack ***all_paths, t_stack **path_to_copy,
				size_t nr_count);
bool		can_be_added_to_path(t_stack **path, t_stack *node);
t_stack		**best_path_for_node(t_stack **path1, t_stack **path2,
				t_stack *node);
void		free_bfs_paths(t_stack ***all_paths, t_stack **best_path);
t_stack		**clean_and_select_best_path(t_stack ***all_paths);
bool		node_in_path(t_stack *node, t_stack **path);
size_t		nr_of_paths(t_stack ***all_paths);
size_t		path_get_length(t_stack **path);
size_t		path_get_last_index(t_stack **path);
size_t		path_get_first_index(t_stack **path);
void		remove_path(t_stack ***all_paths, t_stack **path);
void		compare_and_prune(t_stack ***all_paths, t_stack **new_path);

// algorithm
void		initial_swap(t_data *data);
void		push_all_to_b(t_data *data);
void		define_cheapest_route(t_route *route_data, t_data *data);
void		push_back_to_a(t_data *data);
void		rotate_stack_a_smallest_to_top(t_data *data);
void		small_nr_sort(t_data *data);

// stack utils
t_stack		*stack_get_last(t_stack *stack);
void		free_nodes_in_stack(t_stack *stack);
size_t		stack_len(t_stack *stack);
bool		stack_is_ordered(t_stack *stack);
bool		stack_is_circularly_ordered(t_stack *stack, size_t smallest,
				size_t largest);
size_t		stack_get_smallest(t_stack *stack);
size_t		stack_get_largest(t_stack *stack);

// debug
void		print_stack(t_stack *stack);
char		*str_from_stack(t_stack *stack);
char		*str_from_bfs_path(t_stack **path);
void		print_bfs_path(t_stack **path);
void		print_all_bfs_paths(t_stack ***all_paths);
void		print_nr_of_paths(t_stack ***all_paths);

#endif
