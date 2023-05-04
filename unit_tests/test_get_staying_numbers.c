#include "../sources/push_swap.h"
#include <assert.h>

void test_get_staying_numbers(void)
{
	// ./push_swap 11 0 14 10 6 3 9 1 8 4 12 2 5 7 13
	
	int		argc;
	t_data	data;
	
	char	*argv_1[16] = {"dummy", "11", "0", "14", "10", "6", "3", "9", "1", "8", "4", "12", "2", "5", "7", "13"};
	argc = 16;
	data.nr_count = argc - 1;
	data.stack_a = NULL;
	parse_input(argc, argv_1, &(data.stack_a));
	normalize_input(data.stack_a);
	data.staying_numbers = get_staying_numbers(&data);
	printf("str: %s\n", str_from_bfs_path(data.staying_numbers));
	assert(ft_strncmp("0 1 2 5 7 13 ", str_from_bfs_path(data.staying_numbers), 13) == 0);
	
	char	*argv_2[12] = {"dummy", "3", "4", "5", "6", "9", "10", "7", "8", "0", "1", "2"};
	argc = 12;
	data.stack_a = NULL;
	parse_input(argc, argv_2, &(data.stack_a));
	normalize_input(data.stack_a);
	data.nr_count = argc - 1;
	data.staying_numbers = get_staying_numbers(&data);
	printf("str: %s\n", str_from_bfs_path(data.staying_numbers));
	assert(ft_strncmp("3 4 5 6 7 8 0 1 2 ", str_from_bfs_path(data.staying_numbers), 18) == 0);

	puts("test_get_staying_numbers OK");
}
