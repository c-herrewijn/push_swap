/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_execute.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:17:23 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/21 19:26:15 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_push(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp(command, "pa", 2) == 0)
		push(stack_a, stack_b);
	if (ft_strncmp(command, "pb", 2) == 0)
		push(stack_b, stack_a);
}

static void	execute_swap(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp(command, "sa", 2) == 0)
		swap(stack_a);
	if (ft_strncmp(command, "sb", 2) == 0)
		swap(stack_b);
	if (ft_strncmp(command, "ss", 2) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
}

static void	execute_rotate(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp(command, "rra", 3) == 0)
		rotate(stack_a, 'r');
	if (ft_strncmp(command, "rrb", 3) == 0)
		rotate(stack_b, 'r');
	if (ft_strncmp(command, "rrr", 3) == 0)
	{
		rotate(stack_a, 'r');
		rotate(stack_b, 'r');
	}
	if (ft_strncmp(command, "ra", 2) == 0)
		rotate(stack_a, 'n');
	if (ft_strncmp(command, "rb", 2) == 0)
		rotate(stack_b, 'n');
	if (ft_strncmp(command, "rr", 2) == 0)
	{
		rotate(stack_a, 'n');
		rotate(stack_b, 'n');
	}
}

void	execute_operation(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp(command, "p", 1) == 0)
		execute_push(stack_a, stack_b, command);
	if (ft_strncmp(command, "s", 1) == 0)
		execute_swap(stack_a, stack_b, command);
	if (ft_strncmp(command, "r", 1) == 0)
		execute_rotate(stack_a, stack_b, command);
	write(1, command, ft_strlen(command));
	write(1, "\n", 1);
}
