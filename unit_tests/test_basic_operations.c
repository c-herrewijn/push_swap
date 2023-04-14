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

	swap(&stack_a);
	assert(ft_strncmp("22 11 33 44 ", str_from_stack(stack_a), 12) == 0);

	push_to(&stack_b, &stack_a);
	assert(ft_strncmp("11 33 44 ", str_from_stack(stack_a), 9) == 0);
	assert(ft_strncmp("22 ", str_from_stack(stack_b), 3) == 0);
	// todo: more cases to test the push_to; (push-to empty/not empty; take from empty/not empty) 

	// todo:
	// test rotate();
	// test reverse_rotate();

	puts("test_basic_operations OK");
}
