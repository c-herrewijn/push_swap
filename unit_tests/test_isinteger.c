#include "../sources/push_swap.h"
#include <assert.h>

void test_isinteger(void)
{
	// valid integers
	assert(ft_isinteger("42") == true);
	assert(ft_isinteger("-42") == true);
	assert(ft_isinteger("+42") == true);
	assert(ft_isinteger("0") == true);
	assert(ft_isinteger("-0") == true);
	assert(ft_isinteger("2512314") == true);
	assert(ft_isinteger("-2512314") == true);

	// min max
	assert(ft_isinteger("2147483647") == true); // INT_MAX
	assert(ft_isinteger("-2147483648") == true); // INT_MIN
	char *min = ft_itoa(INT_MIN);
	assert(ft_isinteger(min) == true);
	// printf("min: %s\n", min);
	free(min);
	char *max = ft_itoa(INT_MAX);
	assert(ft_isinteger(max) == true);
	// printf("max: %s\n", max);
	free(max);

	// invalid
	assert(ft_isinteger("") == false);
	assert(ft_isinteger("--1") == false);
	assert(ft_isinteger("--1") == false);
	assert(ft_isinteger("10-") == false);
	assert(ft_isinteger("10A") == false);
	assert(ft_isinteger("10A") == false);
	assert(ft_isinteger(" 10") == false);
	assert(ft_isinteger("1-0") == false);
	assert(ft_isinteger("3.5") == false);
	assert(ft_isinteger("-3.5") == false);
	assert(ft_isinteger("9999999999") == false);  // larger then INT_MAX
	assert(ft_isinteger("-9999999999") == false);  // smaller then INT_MIN
	
	puts("test_integer OK");
}
