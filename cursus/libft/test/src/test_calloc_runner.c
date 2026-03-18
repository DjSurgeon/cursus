#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

int test_calloc(size_t nmemb, size_t size) {
    void *ptr;
    size_t total_size = nmemb * size;
    unsigned char *u_ptr;
    size_t i;

    ptr = ft_calloc(nmemb, size);
    
    // Edge case: nmemb or size is 0
    if (nmemb == 0 || size == 0) {
        if (ptr != NULL) {
            printf("  " GREEN "✅ PASS:" NC " nmemb=%zu, size=%zu -> Unique pointer returned\n", nmemb, size);
            free(ptr);
            return 0;
        } else {
            printf("  " RED "❌ FAIL:" NC " nmemb=%zu, size=%zu -> Returned NULL (expected unique pointer)\n", nmemb, size);
            return 1;
        }
    }

    if (!ptr) {
        printf("  " RED "❌ FAIL:" NC " nmemb=%zu, size=%zu -> Allocation failed (returned NULL)\n", nmemb, size);
        return 1;
    }

    u_ptr = (unsigned char *)ptr;
    for (i = 0; i < total_size; i++) {
        if (u_ptr[i] != 0) {
            printf("  " RED "❌ FAIL:" NC " nmemb=%zu, size=%zu -> Byte at index %zu is not zero (%02x)\n", nmemb, size, i, u_ptr[i]);
            free(ptr);
            return 1;
        }
    }

    printf("  " GREEN "✅ PASS:" NC " nmemb=%zu, size=%zu -> Memory zeroed correctly\n", nmemb, size);
    free(ptr);
    return 0;
}

int main(void) {
    int failed = 0;

    failed |= test_calloc(10, sizeof(int));
    failed |= test_calloc(1, 1);
    failed |= test_calloc(0, 10);
    failed |= test_calloc(10, 0);
    failed |= test_calloc(100, 1);

    return (failed ? 1 : 0);
}
