#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

int test_memcpy(size_t size, size_t n, const char *test_name) {
	unsigned char *src = malloc(size);
	unsigned char *dest1 = malloc(size);
	unsigned char *dest2 = malloc(size);
	int failed = 0;

	if (!src || !dest1 || !dest2) return 1;

	for (size_t i = 0; i < size; i++) {
		src[i] = (unsigned char)(i + 1);
		dest1[i] = 0;
		dest2[i] = 0;
	}

	ft_memcpy(dest1, src, n);
	memcpy(dest2, src, n);

	if (memcmp(dest1, dest2, size) == 0) {
		printf("  " GREEN "✅ PASS:" NC " %s (n=%zu)\n", test_name, n);
	} else {
		printf("  " RED "❌ FAIL:" NC " %s (n=%zu)\n", test_name, n);
		failed = 1;
	}

	free(src);
	free(dest1);
	free(dest2);
	return failed;
}

int main(void) {
	int failed = 0;

	failed |= test_memcpy(10, 5, "Copy partial buffer");
	failed |= test_memcpy(10, 10, "Copy full buffer");
	failed |= test_memcpy(10, 0, "Copy 0 bytes");
	failed |= test_memcpy(100, 100, "Copy large buffer");
	
	if (ft_memcpy(NULL, NULL, 5) == NULL) {
		printf("  " GREEN "✅ PASS:" NC " NULL, NULL case\n");
	} else {
		printf("  " RED "❌ FAIL:" NC " NULL, NULL case\n");
		failed |= 1;
	}

	return (failed ? 1 : 0);
}
