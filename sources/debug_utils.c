#include "push_swap.h"

void print_stack(t_stack *stack)
{
	t_stack *first;

	if (stack == NULL)
		return ;
	first = stack;
	while (true)
	{
		printf("%d ", stack->value);		
		// printf("value: %d - index: %d\n", stack->value, stack->index);		
		// printf("value: %d - index: %d - current: %p, next: %p, previous %p\n", stack->value, stack->index, stack, stack->next, stack->previous);		
		stack = stack->next;
		if (stack == first)
			break ;
	}
	puts("");
}

char *str_from_stack(t_stack *stack)
{
	t_stack *first;
	size_t	malloc_size = 0;
	char	*str;

	// special case: empty stack
	if (stack == NULL)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
		return NULL;
	}
	
	// determine malloc size
	first = stack;
	while (true)
	{
		malloc_size += ft_strlen(ft_itoa(stack->value)) + 1; // add one for space between nbrs
		stack = stack->next;
		if (stack == first)
			break ;
	}
	malloc_size += 1;  // add space for \0-terminator

	// create string
	str = malloc(malloc_size * sizeof(char));
	stack = first;
	while (true)
	{
		ft_strlcat(str, ft_itoa(stack->value), malloc_size);
		ft_strlcat(str, " ", malloc_size);
		stack = stack->next;
		if (stack == first)
			break ;
	}
	return(str);
}
