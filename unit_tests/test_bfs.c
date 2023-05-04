#include "../sources/push_swap.h"
#include <assert.h>


void test_bfs_utils(void)
{
	t_stack node1 = {42, 10, NULL, NULL};
	t_stack node2 = {43, 11, NULL, NULL};
	t_stack **path1;
	t_stack **path2;
	t_data	data;

	data.nr_staying_numbers = 0;
		
	int nr_count = 20;
	t_stack ***all_paths;
	all_paths = ft_calloc((nr_count * 10 + 100), sizeof(t_stack **)); // to decide: number of paths;

	path1 = add_new_path(all_paths, nr_count);
	add_node_to_path(path1, &node1, &data);
	add_node_to_path(path1, &node1, &data);
	add_node_to_path(path1, &node2, &data);
	assert(ft_strncmp("42 42 43 ", str_from_bfs_path(path1), 9) == 0);
	
	path2 = add_new_path(all_paths, nr_count);
	add_node_to_path(path2, &node2, &data);
	assert(ft_strncmp("43 ", str_from_bfs_path(path2), 3) == 0);
	
	duplicate_path(all_paths, path1, nr_count);
	assert(ft_strncmp("42 42 43 ", str_from_bfs_path(all_paths[0]), 9) == 0);
	assert(ft_strncmp("43 ", str_from_bfs_path(all_paths[1]), 3) == 0);
	assert(ft_strncmp("42 42 43 ", str_from_bfs_path(all_paths[2]), 9) == 0);

	puts("test_bfs_utils OK");
}
