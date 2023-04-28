#include "../sources/push_swap.h"
#include <assert.h>

void test_get_staying_numbers(void)
{
	// ./push_swap 11 0 14 10 6 3 9 1 8 4 12 2 5 7 13
	
	int		argc;
	t_stack	*stack_a;
	size_t	nr_count;
	t_stack	**staying_numbers;
	
	char	*argv_1[16] = {"dummy", "11", "0", "14", "10", "6", "3", "9", "1", "8", "4", "12", "2", "5", "7", "13"};
	argc = 16;
	stack_a = NULL;
	parse_input(argc, argv_1, &stack_a);
	normalize_input(stack_a);
	nr_count = argc - 1;
	staying_numbers = get_staying_numbers(stack_a, nr_count);
	assert(ft_strncmp("11 14 3 4 5 7 ", str_from_bfs_path(staying_numbers), 14) == 0);
	
	char	*argv_2[12] = {"dummy", "3", "4", "5", "6", "9", "10", "7", "8", "0", "1", "2"};
	argc = 12;
	stack_a = NULL;
	parse_input(argc, argv_2, &stack_a);
	normalize_input(stack_a);
	nr_count = argc - 1;
	staying_numbers = get_staying_numbers(stack_a, nr_count);
	assert(ft_strncmp("3 4 5 6 7 8 0 1 2 ", str_from_bfs_path(staying_numbers), 18) == 0);

	puts("test_get_staying_numbers OK");
}
