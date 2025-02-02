/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:12:20 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/02 17:12:22 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la estructura del nodo
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Función `del` para liberar cualquier contenido dinámico
void	delete_generic(void *content)
{
	if (content)
	{
		printf("🗑 Liberando contenido: %s\n", (char *)content);
		free(content);
	}
}

// Implementación de `ft_lstclear`
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}

// Función para crear un nuevo nodo
t_list *ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// 🌟 MAIN PARA PROBAR `ft_lstclear`
int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	char	*str1;
	char	*str2;
	char	*str3;

	// Asignamos memoria y copiamos texto en los nodos
	str1 = strdup("Nodo 1");
	str2 = strdup("Nodo 2");
	str3 = strdup("Nodo 3");

	// Creamos los nodos
	head = ft_lstnew(str1);
	node1 = ft_lstnew(str2);
	node2 = ft_lstnew(str3);

	// Enlazamos los nodos
	head->next = node1;
	node1->next = node2;

	// 📌 Imprimimos la lista antes de vaciarla
	printf("Lista antes de vaciarla:\n");
	t_list *temp = head;
	while (temp)
	{
		printf("- %s\n", (char *)temp->content);
		temp = temp->next;
	}

	// 🔥 Vaciamos la lista
	ft_lstclear(&head, delete_generic);

	// 📌 Comprobamos que la lista se ha vaciado
	if (head == NULL)
		printf("✅ Lista vaciada correctamente\n");

	return (0);
}
