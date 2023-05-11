/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 15:10:11 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/11 17:42:42 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// strips a single final newline of a string (replaces with a NULL character)
static char	*strip_newline(char *str)
{
	size_t	len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

static void	silent_execute_command(t_data *data, char *command)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = &(data->stack_a);
	stack_b = &(data->stack_b);
	if (ft_strncmp(command, "p", 1) == 0)
		execute_push(stack_a, stack_b, command);
	if (ft_strncmp(command, "s", 1) == 0)
		execute_swap(stack_a, stack_b, command);
	if (ft_strncmp(command, "r", 1) == 0)
		execute_rotate(stack_a, stack_b, command);
}

static bool	command_valid(char *command)
{
	if (ft_strlen(command) == 2)
	{
		return ((ft_strncmp(command, "sa", 2) == 0)
			|| (ft_strncmp(command, "sb", 2) == 0)
			|| (ft_strncmp(command, "ss", 2) == 0)
			|| (ft_strncmp(command, "pa", 2) == 0)
			|| (ft_strncmp(command, "pb", 2) == 0)
			|| (ft_strncmp(command, "ra", 2) == 0)
			|| (ft_strncmp(command, "rb", 2) == 0)
			|| (ft_strncmp(command, "rr", 2) == 0));
	}
	else if (ft_strlen(command) == 3)
	{
		return ((ft_strncmp(command, "rra", 3) == 0)
			|| (ft_strncmp(command, "rrb", 3) == 0)
			|| (ft_strncmp(command, "rrr", 3) == 0));
	}
	else
		return (false);
}

int	main(int argc, char *argv[])
{
	char	*command;
	t_data	data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	if (is_valid_input(argc, argv) == false)
		exit_with_error(data.stack_a, data.stack_b);
	if (parse_input(argc, argv, &(data.stack_a), &data) < 0)
		exit_with_error(data.stack_a, data.stack_b);
	normalize_input(data.stack_a);
	while (true)
	{
		command = strip_newline(get_next_line(STDIN_FILENO));
		if (command == NULL)
			break ;
		if (command_valid(command))
			silent_execute_command(&data, command);
		else
			exit_with_error(data.stack_a, data.stack_b);
	}
	if (stack_is_ordered(data.stack_a) && data.stack_b == NULL)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_nodes_in_stack(data.stack_a);
}
