#include "../sources/push_swap.h"
#include <assert.h>

void test_basic_operations(void)
{
	// create stack
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	stack_b = NULL;
	char	*argv[5] = {"dummy", "11", "22", "33", "44"};
	int		argc = 5;
	
	parse_input(argc, argv, &stack_a);
	assert(ft_strncmp("11 22 33 44 ", str_from_stack(stack_a), 12) == 0);

	// swap stack of 4
	swap(&stack_a);
	assert(ft_strncmp("22 11 33 44 ", str_from_stack(stack_a), 12) == 0);
	
	// swap stack of 3
	push(&stack_b, &stack_a);
	swap(&stack_a);
	assert(ft_strncmp("33 11 44 ", str_from_stack(stack_a), 9) == 0);
	swap(&stack_a);
	push(&stack_a, &stack_b);

	// swap stack of 2
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	swap(&stack_a);
	assert(ft_strncmp("44 33 ", str_from_stack(stack_a), 6) == 0);
	swap(&stack_a);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	// printf("%s\n", str_from_stack(stack_a));

	// push (starts with "22 11 33 44 ")
	push(&stack_b, &stack_a);
	assert(ft_strncmp("11 33 44 ", str_from_stack(stack_a), 9) == 0);
	assert(ft_strncmp("22 ", str_from_stack(stack_b), 3) == 0);

	push(&stack_b, &stack_a);
	assert(ft_strncmp("33 44 ", str_from_stack(stack_a), 6) == 0);
	assert(ft_strncmp("11 22 ", str_from_stack(stack_b), 6) == 0);

	push(&stack_b, &stack_a);
	assert(ft_strncmp("44 ", str_from_stack(stack_a), 3) == 0);
	assert(ft_strncmp("33 11 22 ", str_from_stack(stack_b), 9) == 0);
	
	push(&stack_b, &stack_a);
	assert(ft_strncmp("", str_from_stack(stack_a), 0) == 0);
	assert(ft_strncmp("44 33 11 22 ", str_from_stack(stack_b), 12) == 0);
	
	push(&stack_a, &stack_b);
	assert(ft_strncmp("44 ", str_from_stack(stack_a), 3) == 0);
	assert(ft_strncmp("33 11 22 ", str_from_stack(stack_b), 9) == 0);

	// rotate
	rotate(&stack_a, 'n');
	assert(ft_strncmp("44 ", str_from_stack(stack_a), 3) == 0);

	rotate(&stack_b, 'n');
	assert(ft_strncmp("11 22 33 ", str_from_stack(stack_b), 9) == 0);

	// reverse rotate
	rotate(&stack_a, 'r');
	assert(ft_strncmp("44 ", str_from_stack(stack_a), 3) == 0);

	rotate(&stack_b, 'r');
	assert(ft_strncmp("33 11 22 ", str_from_stack(stack_b), 9) == 0);

	// -------------------------
	// a-typical cases: program should not crash, action should have no effect!
	
	// swap stack with 1 items
	swap(&stack_a);
	assert(ft_strncmp("44 ", str_from_stack(stack_a), 3) == 0);
	
	// swap stack with 0 items
	push(&stack_b, &stack_a);
	assert(ft_strncmp("", str_from_stack(stack_a), 0) == 0);
	swap(&stack_a);
	assert(ft_strncmp("", str_from_stack(stack_a), 0) == 0);

	// try to push from a stack that has no itmes
	push(&stack_b, &stack_a);
	assert(ft_strncmp("", str_from_stack(stack_a), 0) == 0);
	assert(ft_strncmp("44 33 11 22 ", str_from_stack(stack_b), 12) == 0);

	// rotate empty stack
	rotate(&stack_a, 'n');
	assert(ft_strncmp("", str_from_stack(stack_a), 0) == 0);
	
	rotate(&stack_a, 'r');
	assert(ft_strncmp("", str_from_stack(stack_a), 0) == 0);

	puts("test_basic_operations OK");
}
