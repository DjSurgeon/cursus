#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

int test_memcmp(const void *s1, const void *s2, size_t n, const char *test_name) {
	int expected = memcmp(s1, s2, n);
	int actual = ft_memcmp(s1, s2, n);

	// In memcmp, only the sign matters
	if ((expected == 0 && actual == 0) || 
		(expected > 0 && actual > 0) || 
		(expected < 0 && actual < 0)) {
		printf("  " GREEN "✅ PASS:" NC " %s\n", test_name);
		return 0;
	} else {
		printf("  " RED "❌ FAIL:" NC " %s -> Expected sign: %d, Actual: %d\n", test_name, expected, actual);
		return 1;
	}
}

int main(void) {
	int failed = 0;

	failed |= test_memcmp("abc", "abc", 3, "Equal strings");
	failed |= test_memcmp("abc", "abd", 3, "Different at the end");
	failed |= test_memcmp("aba", "abc", 3, "First string less than second");
	failed |= test_memcmp("abc", "aba", 3, "First string greater than second");
	failed |= test_memcmp("abc", "abcdef", 3, "Equal up to n");
	failed |= test_memcmp("abcdef", "abc", 3, "Equal up to n (longer s1)");
	failed |= test_memcmp("abc", "abc", 0, "n = 0");
	
	// Test with unsigned char values
	unsigned char s1[] = {0, 0, 127, 255};
	unsigned char s2[] = {0, 0, 127, 0};
	failed |= test_memcmp(s1, s2, 4, "Unsigned char comparison");

	return (failed ? 1 : 0);
}
