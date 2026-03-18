#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

int test_itoa(int n, const char *expected) {
	char *actual = ft_itoa(n);
	
	if (actual == NULL) {
		printf("  " RED "❌ FAIL:" NC " Input %d -> Returned NULL, Expected: \"%s\"\n", n, expected);
		return 1;
	}

	if (strcmp(actual, expected) == 0) {
		printf("  " GREEN "✅ PASS:" NC " Input %d -> \"%s\"\n", n, actual);
		free(actual);
		return 0;
	} else {
		printf("  " RED "❌ FAIL:" NC " Input %d -> Expected: \"%s\", Actual: \"%s\"\n", n, expected, actual);
		free(actual);
		return 1;
	}
}

int main(void) {
	int failed = 0;

	failed |= test_itoa(0, "0");
	failed |= test_itoa(42, "42");
	failed |= test_itoa(-42, "-42");
	failed |= test_itoa(123456, "123456");
	failed |= test_itoa(-123456, "-123456");
	failed |= test_itoa(2147483647, "2147483647");
	failed |= test_itoa(-2147483648, "-2147483648");

	return (failed ? 1 : 0);
}
