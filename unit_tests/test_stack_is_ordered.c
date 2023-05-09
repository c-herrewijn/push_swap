#include "../sources/push_swap.h"
#include <assert.h>

void test_stack_is_orderd(void)
{
	int		argc;
	t_data	data;
	puts("testing stack_is_orderd...");

	t_stack	*stack_1;
	stack_1 = NULL;
	char	*argv_1[6] = {"dummy", "11", "22", "33", "44", NULL};
	argc = 5;
	parse_input(argc, argv_1, &stack_1, &data);
	normalize_input(stack_1);
	assert(stack_is_ordered(stack_1) == true); 


	t_stack	*stack_2;
	stack_2 = NULL;
	char	*argv_2[6] = {"dummy", "11", "22", "44", "33", NULL};
	argc = 5;
	parse_input(argc, argv_2, &stack_2, &data);
	normalize_input(stack_2);
	assert(stack_is_ordered(stack_2) == false); 


	t_stack	*stack_3;
	stack_3 = NULL;
	char	*argv_3[3] = {"dummy", "11", NULL};
	argc = 2;
	parse_input(argc, argv_3, &stack_3, &data);
	normalize_input(stack_3);
	assert(stack_is_ordered(stack_3) == true); 


	t_stack	*stack_4;
	stack_4 = NULL;
	char	*argv_4[4] = {"dummy", "11", "22", NULL};
	argc = 3;
	parse_input(argc, argv_4, &stack_4, &data);
	normalize_input(stack_4);
	assert(stack_is_ordered(stack_4) == true); 


	t_stack	*stack_5;
	stack_5 = NULL;
	char	*argv_5[4] = {"dummy", "22", "11", NULL};
	argc = 3;
	parse_input(argc, argv_5, &stack_5, &data);
	normalize_input(stack_5);
	assert(stack_is_ordered(stack_5) == false);

	puts("test_stack_is_ordered OK");

	assert(stack_is_circularly_ordered(stack_1, stack_get_smallest(stack_1), stack_get_largest(stack_1)) == true); 
	assert(stack_is_circularly_ordered(stack_2, stack_get_smallest(stack_2), stack_get_largest(stack_2)) == false); 
	assert(stack_is_circularly_ordered(stack_3, stack_get_smallest(stack_3), stack_get_largest(stack_3)) == true); 
	assert(stack_is_circularly_ordered(stack_4, stack_get_smallest(stack_4), stack_get_largest(stack_4)) == true); 
	assert(stack_is_circularly_ordered(stack_5, stack_get_smallest(stack_5), stack_get_largest(stack_5)) == true); 
	
	t_stack	*stack_6;
	stack_6 = NULL;
	char	*argv_6[6] = {"dummy", "22", "33", "0", "11", NULL};
	argc = 5;
	parse_input(argc, argv_6, &stack_6, &data);
	normalize_input(stack_6);
	assert(stack_is_circularly_ordered(stack_6, stack_get_smallest(stack_6), stack_get_largest(stack_6)) == true); 
	
	t_stack	*stack_7;
	stack_7 = NULL;
	char	*argv_7[6] = {"dummy", "1", "3", "0", "2", NULL};
	argc = 5;
	parse_input(argc, argv_7, &stack_7, &data);
	normalize_input(stack_7);
	assert(stack_is_circularly_ordered(stack_7, stack_get_smallest(stack_7), stack_get_largest(stack_7)) == false); 
	
	
	t_stack	*stack_8;
	stack_8 = NULL;
	char	*argv_8[5] = {"dummy", "1", "2", "0", NULL};
	argc = 4;
	parse_input(argc, argv_8, &stack_8, &data);
	normalize_input(stack_8);
	assert(stack_is_circularly_ordered(stack_8, stack_get_smallest(stack_8), stack_get_largest(stack_8)) == true); 
	
	puts("test_stack_is_circularly_ordered OK");
}
