/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_new_strings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:39:57 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/02 15:26:56 by serjimen         ###   ########.fr       */
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
int main(void)
{
	char 		*string = "Hola 42!";				// declaramos el puntero del contenido
	t_list 		*my_node;				// variable para almacenar la lista
	
	string = malloc(9 * sizeof(char));		// malloc del contenido
		if (!string)
			return(0);

	// string = "Hola 42!";						// valor del puntero
	my_node = ft_lstnew(string);		// ejecutamos la funcion 
	
	if (!my_node)
	{
		free(my_node);
		return (0);
	}
	
	printf("Contenido del nodo: %s\n", (char *)my_node->content);
	printf("Puntero al siguiente nodo: %p\n", my_node->next);
	
	free(string);
	free(my_node);
	
	return (0);
}