#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

void toupper_content(void *content) {
	char *s = (char *)content;
	while (*s) {
		*s = toupper((unsigned char)*s);
		s++;
	}
}

void del_content(void *content) {
	free(content);
}

int main(void) {
	t_list *list = NULL;
	char *s1 = strdup("abc");
	char *s2 = strdup("def");
	char *s3 = strdup("ghi");
	
	ft_lstadd_back(&list, ft_lstnew(s1));
	ft_lstadd_back(&list, ft_lstnew(s2));
	ft_lstadd_back(&list, ft_lstnew(s3));

	// Test 1: Iterate and modify
	ft_lstiter(list, toupper_content);

	if (strcmp(list->content, "ABC") == 0 &&
		strcmp(list->next->content, "DEF") == 0 &&
		strcmp(list->next->next->content, "GHI") == 0) {
		printf("  " GREEN "✅ PASS:" NC " All nodes modified correctly\n");
	} else {
		printf("  " RED "❌ FAIL:" NC " Nodes not modified correctly\n");
		return 1;
	}

	// Test 2: NULL inputs
	ft_lstiter(NULL, toupper_content);
	ft_lstiter(list, NULL);
	printf("  " GREEN "✅ PASS:" NC " NULL inputs handled correctly\n");

	// Cleanup
	ft_lstclear(&list, del_content);

	return 0;
}
