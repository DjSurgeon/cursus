#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

static int g_del_count = 0;

void del_content(void *content) {
	free(content);
	g_del_count++;
}

int main(void) {
	char *s = strdup("test content");
	t_list *node = ft_lstnew(s);

	if (!node) {
		printf("  " RED "❌ FAIL:" NC " Memory allocation failed\n");
		return 1;
	}

	// Test 1: Delete one node
	ft_lstdelone(node, del_content);

	if (g_del_count == 1) {
		printf("  " GREEN "✅ PASS:" NC " del function called correct number of times (1)\n");
	} else {
		printf("  " RED "❌ FAIL:" NC " del function called %d times, expected 1\n", g_del_count);
		return 1;
	}

	// Test 2: NULL inputs
	ft_lstdelone(NULL, del_content);
	ft_lstdelone(NULL, NULL);
	printf("  " GREEN "✅ PASS:" NC " NULL inputs handled correctly\n");

	return 0;
}
