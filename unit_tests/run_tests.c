#include "../sources/push_swap.h"

void test_isinteger(void);
void test_basic_operations(void);
void test_bfs_utils(void);
void test_get_staying_numbers(void);
void test_ft_abs(void);
void test_stack_is_orderd(void);

int main(void)
{
	puts("starting tests...");
	test_isinteger();
	test_basic_operations();
	test_bfs_utils();
	test_get_staying_numbers();
	test_ft_abs();
	test_stack_is_orderd();
}
