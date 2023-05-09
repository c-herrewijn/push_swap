/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spaced_arguments.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 16:07:31 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/05/09 13:14:37 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_arr(char **arr)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

static int	parse_spaced_numbers(char **arr, t_stack **stack_a)
{
	t_stack	*last;
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{	
		if (add_new_to_stack(ft_atoi(arr[i]), stack_a) < 0)
			return (-1);
		i++;
	}
	last = stack_get_last(*stack_a);
	last->next = *stack_a;
	(*stack_a)->previous = last;
	return (0);
}

// returns the number of integers
// return '0' means there is at least 1 non-integer or duplicate
static size_t	validate_integers_and_duplicates(char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arr[i] != NULL)
	{
		if (ft_isinteger(arr[i]) == false)
			return (0);
		j = 0;
		while (j < i)
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

// NOTE: exits if there is exactly 1 number, since no sorting is required
int	validate_and_parse_spaced_numbers(char *str, t_stack **stack_a,
	t_data *data)
{
	char	**arr;
	size_t	number_of_numbers;

	arr = ft_split(str, ' ');
	if (arr == NULL)
		return (-1);
	if (ft_isinteger(arr[0]) && arr[1] == NULL)
	{
		free_arr(arr);
		exit(0);
	}
	number_of_numbers = validate_integers_and_duplicates(arr);
	if (number_of_numbers == 0)
	{
		free_arr(arr);
		return (-1);
	}
	if (parse_spaced_numbers(arr, stack_a) < 0)
	{
		free_arr(arr);
		return (-1);
	}
	free_arr(arr);
	data->nr_count = number_of_numbers;
	return (0);
}
