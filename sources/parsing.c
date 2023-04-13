/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 16:32:57 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/04/13 19:55:40 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
check if string has format:
optionally starts with a plus '+' or minus '-' sign
only consists of digits [0-9]
is within range [INT_MIN, INT_MAX]
*/
bool	ft_isinteger(char *int_str)
{
	int			i;
	int			sign;
	long int	num;

	if (int_str == NULL || int_str[0] == '\0')
		return (false);
	i = 0;
	sign = 1;
	if (int_str[0] == '-')
		sign = -1;
	if (int_str[0] == '-' || int_str[0] == '+')
		i++;
	num = 0;
	while (int_str[i] != '\0')
	{
		if (ft_isdigit(int_str[i]) == false)
			return (false);
		num = num * 10;
		num = num + (int_str[i] - 48);
		i++;
	}
	num = num * sign;
	return (num >= INT_MIN && num <= INT_MAX);
}

static void	normalize_input(t_stack *stack)
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
static int	add_new_to_stack(int num, t_stack **stack)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
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

int	parse_input(int argc, char *argv[], t_stack **stack_a)
{
	t_stack	*last;
	int		i;

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
	return (0);
}
