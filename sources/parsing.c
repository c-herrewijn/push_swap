/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 16:32:57 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/09 15:08:44 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_input(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	size_t	count;

	i = stack;
	while (true)
	{
		j = stack;
		count = 0;
		while (true)
		{
			if (i->value > j->value)
				count++;
			j = j->next;
			if (j == stack)
				break ;
		}
		i->index = count;
		i = i->next;
		if (i == stack)
			break ;
	}
}

// assumes there is no circular reference in the stack yet
int	add_new_to_stack(int num, t_stack **stack)
{
	t_stack	*new;
	t_stack	*last;

	new = ft_calloc(1, sizeof(t_stack));
	if (new == NULL)
		return (-1);
	new->value = num;
	new->next = NULL;
	new->previous = NULL;
	new->index = 0;
	if (*stack == NULL)
		*stack = new;
	else
	{
		last = stack_get_last(*stack);
		last->next = new;
		new->previous = last;
	}
	return (0);
}

int	parse_input(int argc, char *argv[], t_stack **stack_a, t_data *data)
{
	t_stack	*last;
	int		i;

	if (argc == 2)
	{
		if (ft_isinteger(argv[1]) == true)
			exit(0);
		if (validate_and_parse_spaced_numbers(argv[1], stack_a, data) < 0)
			return (-1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (add_new_to_stack(ft_atoi(argv[i]), stack_a) < 0)
				return (-1);
			i++;
		}
		last = stack_get_last(*stack_a);
		last->next = *stack_a;
		(*stack_a)->previous = last;
		data->nr_count = argc - 1;
	}
	return (0);
}
