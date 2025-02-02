/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:30:57 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/02 16:25:51 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

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

int main(void)
{
	t_list	*root;						// declaramos el primer nodo
	t_list	*node2;						// declaramos el segundo nodo
	t_list	*node3;
	t_list	*node4;
	int		result;						// variable para el resultado
	t_list *resultnode;
	int		num1;
	int		num2;
	int		num3;
	int		num4;
	

	num1 = 42;
	num2 = 24;
	num3 = -34;
	num4 = 99;
	root = malloc(sizeof(t_list));
	if (!root)
		return (0);
	node2 = malloc(sizeof(t_list));
	if (!node2)
		return (0);
	node3 = malloc(sizeof(t_list));
	if (!node3)
		return (0);
	node4 = malloc(sizeof(t_list));
	if (!node4)
		return (0);
	root->content = &num1;
	root->next = node2;
	node2->content = &num2;
	node2->next = node3;
	node3->content = &num3;
	node3->next = NULL;
	node4->content = &num4;
	node4->next = NULL;
	result = ft_lstsize(root);				// tamaño de la lista
	resultnode = ft_lstlast(root);			// nos devuelve el ultimo nodo de la lista
	
	printf("La lista contiene %i nodos.\n", result);
	printf("El ultimo nodo de la lista, contiene el int: %i\n", *(int *)resultnode->content);
	ft_lstadd_back(&root, node4);
	result = ft_lstsize(root);				// tamaño de la lista
	resultnode = ft_lstlast(root);			// nos devuelve el ultimo nodo de la lista
	printf("La lista contiene %i nodos.\n", result);
	printf("El ultimo nodo de la lista, contiene el int: %i\n", *(int *)resultnode->content);

	free(node4);
	free(node3);
	free(node2);
	free(root);
	
	return (0);
}