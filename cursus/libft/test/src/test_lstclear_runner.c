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
	t_list *list = NULL;
	char *s1 = strdup("node1");
	char *s2 = strdup("node2");
	char *s3 = strdup("node3");
	t_list *n1 = ft_lstnew(s1);
	t_list *n2 = ft_lstnew(s2);
	t_list *n3 = ft_lstnew(s3);

	if (!n1 || !n2 || !n3) {
		printf("  " RED "❌ FAIL:" NC " Memory allocation failed\n");
		return 1;
	}

	ft_lstadd_back(&list, n1);
	ft_lstadd_back(&list, n2);
	ft_lstadd_back(&list, n3);

	// Test 1: Clear the list
	ft_lstclear(&list, del_content);

	if (list == NULL) {
		printf("  " GREEN "✅ PASS:" NC " List pointer is NULL after ft_lstclear\n");
	} else {
		printf("  " RED "❌ FAIL:" NC " List pointer is NOT NULL after ft_lstclear\n");
		return 1;
	}

	if (g_del_count == 3) {
		printf("  " GREEN "✅ PASS:" NC " del function called correct number of times (3)\n");
	} else {
		printf("  " RED "❌ FAIL:" NC " del function called %d times, expected 3\n", g_del_count);
		return 1;
	}

	// Test 2: Clear empty list
	list = NULL;
	ft_lstclear(&list, del_content);
	if (list == NULL) {
		printf("  " GREEN "✅ PASS:" NC " Clearing empty list handled correctly\n");
	} else {
		printf("  " RED "❌ FAIL:" NC " Clearing empty list failed\n");
		return 1;
	}

	return 0;
}
