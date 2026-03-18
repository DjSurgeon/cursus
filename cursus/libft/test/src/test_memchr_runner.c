#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

int test_memchr(const void *s, int c, size_t n, const char *test_name) {
	void *expected = memchr(s, c, n);
	void *actual = ft_memchr(s, c, n);

	if (expected == actual) {
		printf("  " GREEN "✅ PASS:" NC " %s\n", test_name);
		return 0;
	} else {
		printf("  " RED "❌ FAIL:" NC " %s -> Expected: %p, Actual: %p\n", test_name, expected, actual);
		return 1;
	}
}

int main(void) {
	int failed = 0;
	char str[] = "Hello World!";
	int tab[] = {0, 1, 2, 42, 127, 255};

	failed |= test_memchr(str, 'W', 12, "Search 'W' in 'Hello World!'");
	failed |= test_memchr(str, 'H', 12, "Search 'H' at the beginning");
	failed |= test_memchr(str, '!', 12, "Search '!' at the end");
	failed |= test_memchr(str, 'x', 12, "Search non-existent character");
	failed |= test_memchr(str, 'o', 5, "Search 'o' within limited range");
	failed |= test_memchr(str, 'o', 4, "Search 'o' just outside range");
	failed |= test_memchr(str, '\0', 13, "Search null terminator");
	failed |= test_memchr(str, 'W', 0, "Search with n = 0");
	failed |= test_memchr(tab, 42, sizeof(tab), "Search 42 in int array");
	failed |= test_memchr(tab, 255, sizeof(tab), "Search 255 (unsigned char check)");

	return (failed ? 1 : 0);
}
