/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:50:22 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/02 16:50:27 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Definimos la estructura del nodo
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Prototipos de funciones
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
void	delete_int(void *content);
void	print_list(t_list *lst);

// Implementación de la función `ft_lstdelone`
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);  // Llamamos a la función `del` para eliminar el contenido del nodo
	free(lst);          // Liberamos la memoria del nodo en sí
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

// Función `del` que elimina un entero (para nuestro caso)
void	delete_int(void *content)
{
	// En este caso, la memoria de `content` no necesita ser liberada
	// porque es un puntero a una variable estática en `main`
	printf("🗑 Eliminando el contenido: %d\n", *(int *)content);
}

// Función para imprimir la lista
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

// 🌟 MAIN PARA PROBAR `ft_lstdelone`
int	main(void)
{
	t_list	*head;  
	t_list	*node2;
	int		num1 = 10, num2 = 20;

	// Creamos dos nodos
	head = ft_lstnew(&num1);
	node2 = ft_lstnew(&num2);
	
	// Conectamos los nodos (head → node2)
	head->next = node2;

	// 🔹 Mostramos la lista antes de eliminar un nodo
	printf("Lista enlazada antes de `ft_lstdelone`:\n");
	print_list(head);

	// 🔥 Eliminamos el primer nodo
	ft_lstdelone(head, delete_int);

	// ❌ No podemos imprimir `head` porque ya ha sido eliminado
	// Así que ahora `node2` es la nueva cabeza de la lista
	printf("Lista enlazada después de `ft_lstdelone`:\n");
	print_list(node2);

	// Liberamos el nodo restante
	free(node2);

	return (0);
}
