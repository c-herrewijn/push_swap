#include "../sources/push_swap.h"
#include <assert.h>

void test_stack_is_orderd(void)
{
	int		argc;
	puts("testing stack_is_orderd...");

	t_stack	*stack_1;
	stack_1 = NULL;
	char	*argv_1[6] = {"dummy", "11", "22", "33", "44", NULL};
	argc = 5;
	parse_input(argc, argv_1, &stack_1);
	normalize_input(stack_1);
	assert(stack_is_ordered(stack_1) == true); 


	t_stack	*stack_2;
	stack_2 = NULL;
	char	*argv_2[6] = {"dummy", "11", "22", "44", "33", NULL};
	argc = 5;
	parse_input(argc, argv_2, &stack_2);
	normalize_input(stack_2);
	assert(stack_is_ordered(stack_2) == false); 


	t_stack	*stack_3;
	stack_3 = NULL;
	char	*argv_3[3] = {"dummy", "11", NULL};
	argc = 2;
	parse_input(argc, argv_3, &stack_3);
	normalize_input(stack_3);
	assert(stack_is_ordered(stack_3) == true); 


	t_stack	*stack_4;
	stack_4 = NULL;
	char	*argv_4[4] = {"dummy", "11", "22", NULL};
	argc = 3;
	parse_input(argc, argv_4, &stack_4);
	normalize_input(stack_4);
	assert(stack_is_ordered(stack_4) == true); 


	t_stack	*stack_5;
	stack_5 = NULL;
	char	*argv_5[4] = {"dummy", "22", "11", NULL};
	argc = 3;
	parse_input(argc, argv_5, &stack_5);
	normalize_input(stack_5);
	assert(stack_is_ordered(stack_5) == false);

	puts("test_stack_is_ordered OK");
}
