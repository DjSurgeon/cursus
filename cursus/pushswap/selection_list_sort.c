/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_list_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:48:52 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/18 16:36:09 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Estructura de la nodos
typedef struct s_list
{
	size_t			id;
	char			*title;
	int				nlisten;
	struct s_list	*next;
}					t_list;

// Creacion de nodo
t_list	*ft_lstnew(size_t id, int number, char *song)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if(!new_node)
		return (NULL);
	new_node->id = id;
	new_node->title = song;
	new_node->nlisten = number;
	new_node->next = NULL;
	return (new_node);
}

// Añadir nodo al principio
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// Añadir una escucha
void listen(t_list *list, size_t id)
{
	while (list != NULL)
	{
		if (list->id == id)
		{
			list->nlisten += 1;
			return ;
		}
		list = list->next;
	}
}

int main (void)
{
	t_list *spotify_1;
	t_list *spotify_2;
	t_list	*find;

	spotify_1 = ft_lstnew(0, 0, "prodigy");
	spotify_2 = ft_lstnew(1, 0, "radiohead");
	printf("->escuchas: %d\n->autor: %s\n", spotify_1->nlisten, spotify_1->title);
	ft_lstadd_front(&spotify_1, spotify_2);
	listen(spotify_1, 0);
	listen(spotify_1, 0);
	find = spotify_1;
	
	printf("->escuchas: %d\n->autor: %s\n", spotify_1->nlisten, spotify_1->title);

	return (0);
}