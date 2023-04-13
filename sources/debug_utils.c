#include "push_swap.h"

void print_stack(t_stack *stack)
{
	t_stack *first;

	if (stack == NULL)
		return ;
	first = stack;
	while (true)
	{
		printf("value: %d - index: %d\n", stack->value, stack->index);		
		// printf("value: %d - index: %d - current: %p, next: %p, previous %p\n", stack->value, stack->index, stack, stack->next, stack->previous);		
		stack = stack->next;
		if (stack == first)
			break ;
	}
}
