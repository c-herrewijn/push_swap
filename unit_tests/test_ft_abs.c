#include "../sources/push_swap.h"
#include <assert.h>

void test_ft_abs(void)
{
	assert(ft_abs(42) == 42);
	assert(ft_abs(-42) == 42);
	assert(ft_abs(0) == 0);
	assert(ft_abs(INT_MAX) == INT_MAX);
	assert(ft_abs(INT_MIN) == INT_MIN);  // this is a 'bug' that also exists in the official abs() function
	assert(ft_abs(INT_MIN + 1) == INT_MAX);

	puts("test_ft_abs OK");
}
