/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lis_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:16:54 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/31 16:23:21 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list					// estructura del nodo de la lista
{										// debe implementarse en libft.h
	void				*content;		// contenido puntero void
	struct s_list		*next;			// puntero al siguiente nodo
}						t_list;			// nombre de la lista

/*
** descripcion: funcion para crear un nuevo nodo
** parametros: el contenido del nuevo nodo
** retorno:  el nuevo nodo
*/

t_list *ft_lstnew(void *content)		// t_list(valor devuelto) *ft_lstnew(nombre de la función)
{										// void *content(contenido que le quieres dar al nodo, cualquier valor)
	t_list	*new_node;					// declaramos el nuevo nodo

	new_node = malloc(sizeof(t_list));	// asignamos la memoria con malloc del tamaño de nuestro nodo
	if (!new_node)						// verificamos si se asigna bien la memoria
		return (NULL);
	new_node->content = content;		// asignamos el content a content
	new_node->next = NULL;				// y el puntero al siguiente nodo se inicializa en NULL, ya que solo tenemos uno

	return (new_node);					// retornamos el nuevo nodo
}
/*
** descripcion: añade el nodo new al principio de la lista
** parametros: la direccion al primer nodo de la lista
** retorno: un puntero al nodo que añadiremos a la lista
*/
void	ft_lstadd_front(t_list **lst, t_list *new)		
{
	t_list		**root;
	
	root = new;
}

int	main(void)
{
	// int					number;
	char				*string;
	t_list				*my_node;

	// number = 42;
	string = "Hi 42";
	// my_node = ft_lstnew(&number);
	my_node = ft_lstnew(string);
	// printf("Contenido del nuevo nodo es: %i\n", *(int *)(my_node->content));
	printf("Contenido del nuevo nodo es: %s\n", (char *)my_node->content);
	printf("Y el contenido del puntero al siguiente nodo es: %s\n", (char *)my_node->next);
	free(my_node);
	
	return (0);	
}