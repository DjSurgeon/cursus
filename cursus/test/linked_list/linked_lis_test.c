/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lis_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:16:54 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/03 10:41:22 by serjimen         ###   ########.fr       */
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
void	ft_lstadd_front(t_list **lst, t_list *new)		// el parametro **lst es un puntero que apunta al primer nodo
{														// apunta a la direccion de memoria del primer nodo.
														// el segundo parametro es el nuevo nodo
	new->next = *lst;									// ahora el puntero de new apunta a la direccion de *lst
														// lo que quiere decir que new es el primer nodo de la lista
	*lst = new;											// y aquie el puntero lst le indicamos que es el primero.
	// en la linea superior le decimos que la n ueva cabeza de lista en new.
}

int	ft_lstsize(t_list *lst)				// el parametro lst indica el principio de la lista
{										// declararemos size que sera el valor que devolveremos
	int		size;
	
	size = 0;							// inicializamos size
	while (lst)							// while lst el puntero sea true, while(lst != NULL)
	{									// entraremos al bucle
		size++;							// añadiremos 1 al contador
		lst = lst->next;				// lst apuntara al siguiente nodo
	}	
	return (size);						// retornaremos size
}

/*
** devuelve el ultimo nodo de la lista
*/

t_list	*ft_lstlast(t_list *lst)		// el parametro en el principio de la lista
{
	t_list	*last;						// variable a devolver
	
	if (!lst)
		return (NULL);
	while (lst->next != NULL)			// condicion de entrada que el puntero al siguiente nodo no sea NULL
	{
		lst = lst->next;				// vamos iterando
	}
	last = lst;							// hemos itrado por la lista y el puntero apunta al final
	return (last);						// devolvemos el ultimo puntero de la lista
}

void	ft_lstadd_back(t_list **lst, t_list *new)	// parametro puntero al primer nodo, y el puntero del nuevo nodo
{
	t_list	*last;									// declaramos un puntero last
	
	if (!lst || !new)								// si algun valor no existe saldremos de la función
		return ;
	if (*lst == NULL)								// si el puntero de la cabeza de la lista apunta a NULL eso quiere decir
	{												// que la lista esta vacia
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);						// usa nuestra funcion
	last->next = new;
	
}

void	ft_lstdelone(t_list *lst, void(*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	
	free(lst);
}
void	ft_lstclear(t_list **lst, void(*del)(void *))
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
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
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