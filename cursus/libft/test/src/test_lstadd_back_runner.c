#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

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

	// Test 1: Add to empty list
	ft_lstadd_back(&list, n1);
	if (list == n1 && list->next == NULL) {
		printf("  " GREEN "✅ PASS:" NC " Add to empty list\n");
	} else {
		printf("  " RED "❌ FAIL:" NC " Add to empty list\n");
		return 1;
	}

	// Test 2: Add second node
	ft_lstadd_back(&list, n2);
	if (list == n1 && list->next == n2 && n2->next == NULL) {
		printf("  " GREEN "✅ PASS:" NC " Add second node\n");
	} else {
		printf("  " RED "❌ FAIL:" NC " Add second node\n");
		return 1;
	}

	// Test 3: Add third node
	ft_lstadd_back(&list, n3);
	if (list == n1 && n1->next == n2 && n2->next == n3 && n3->next == NULL) {
		printf("  " GREEN "✅ PASS:" NC " Add third node\n");
	} else {
		printf("  " RED "❌ FAIL:" NC " Add third node\n");
		return 1;
	}

	// Cleanup
	free(n1->content);
	free(n1);
	free(n2->content);
	free(n2);
	free(n3->content);
	free(n3);

	return 0;
}
