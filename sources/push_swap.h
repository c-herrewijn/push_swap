/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 11:41:20 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/13 20:29:48 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	unsigned int	index;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

bool	ft_isinteger(char *int_str);
t_stack	*stack_get_last(t_stack *stack);
int		parse_input(int argc, char *argv[], t_stack **stack_a);
void	normalize_input(t_stack *stack);

// debug
void print_stack(t_stack *stack);

#endif
