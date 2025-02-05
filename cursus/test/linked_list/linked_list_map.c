/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:24:41 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/05 22:59:49 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	last = lst;
	return (last);
}
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_node;
	t_list	*result_list;

	result_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		result_node = ft_lstnew(f(lst->content));
		if (!result_node)
		{
			ft_lstclear(&result_node, del);
			return (NULL);
		}
		ft_lstadd_back(&result_list, result_node);
		lst = lst->next;
	}
	return (result_list);
}
void *plus1(void *num)
{
	int *new_num = malloc(sizeof(int));
	if (!new_num)
		return (NULL);
	*new_num = (*(int *)num) * 2;
	return (new_num);
}

void	del(void *content)
{
	if (content)
		free(content);
}
int main(void)
{
	int *value = malloc(sizeof(int));
	*value = 2;
	t_list *head = ft_lstnew(value);

	printf("%d\n", *(int *)(head->content));
	
	t_list *map = ft_lstmap(head, plus1, del);
	
	printf("%d\n", *(int *)(map->content));

	ft_lstclear(&head, del);
	ft_lstclear(&map, del);

	return (0);
}