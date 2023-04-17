#include "../sources/push_swap.h"

void test_isinteger(void);
void test_basic_operations(void);
void test_bfs_utils(void);

int main(void)
{
	puts("starting tests...");
	test_isinteger();
	test_basic_operations();
	test_bfs_utils();
}
