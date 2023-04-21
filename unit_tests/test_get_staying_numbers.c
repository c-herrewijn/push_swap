#include "../sources/push_swap.h"
#include <assert.h>

void test_get_staying_numbers(void)
{
	// ./push_swap 11 0 14 10 6 3 9 1 8 4 12 2 5 7 13
	
	char	*argv[16] = {"dummy", "11", "0", "14", "10", "6", "3", "9", "1", "8", "4", "12", "2", "5", "7", "13"};
	int		argc = 16;
	t_stack	*stack_a;
	size_t	nr_count;
	t_stack	**staying_numbers;
	
	stack_a = NULL;
	parse_input(argc, argv, &stack_a);
	normalize_input(stack_a);
	nr_count = argc - 1;
	staying_numbers = get_staying_numbers(stack_a, nr_count);
	
	assert(ft_strncmp("0 1 2 5 7 13 ", str_from_bfs_path(staying_numbers), 13) == 0);
	
	puts("test_get_staying_numbers OK");
}
