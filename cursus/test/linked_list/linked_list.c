/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:55:11 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/31 12:33:43 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node						// Para declarar un nodo de una lista, lo primero que hay que hacer es declarar una estructura
{											// el nodo como mínimo tendra un valor, en este caso n y un puntero al siguiente nodo
	int				n;						// el valor puede almacenar cualquier tipo de dato.
	struct s_node	*next;					// y el puntero, apunta a la dirección de memoria del siguiente nodo, en el caso
}				t_node;						// de que sea NULL será el último nodo de la lista.

int main(void)
{
	t_node	*root;								// declaramos un puntero al primer nodo
	
	root = malloc(sizeof(t_node));				// asignamos la cantidad de memoria del primero nodo
		if (!root)								// verificamos si malloc falló
			return (1);							// Se termina el programa y devolvemos NULL
	root->next = malloc(sizeof(t_node));		// asignamos la cantidad de memoria del segundo nodo
		if (!root->next)
		{
			free(root);							// liberamos root antes de salir
			return (1);
		}
	root->next->next = malloc(sizeof(t_node));	// asignamos la cantidad de memoria del tercer nodo
		if (!root->next->next)
		{
			free(root->next);					// hay que libear también los nodos previos
			free(root);
			return (1);
		}
	
	root->n = 42;						// asignamos valor al primer nodo
	root->next->n = 24;					// asignamos valor al segundo nodo
	root->next->next->n = 12;			// asignamos valor al tercer nodo
	root->next->next->next = NULL;		// el puntero del tercer nodo es NULL para indicar que es el último

	// vamos a iterar sobre los nodos, para printear el valor por pantalla de cada nodo, como si fuera una string
	// en una string iteramos con i hasta que el valor sera != '\0'. En este caso vamos a iterar con un puntero.
	// hasta que el puntero *current sea NULL

	t_node	*current;		// declaramos el puntero por convención los vamos a llamar current

	current = root;			// el puntero apuntara a la primera posición del nodo
	while (current) 		// esta expresión es equivalente a "while (current != NULL)"
	{
		printf("%d\n", current->n); 	// en esta línea le decimos a current que imprime el valor de n
		current = current->next;		// en esta línea asignamos a current la dirección de memoria del siguiente nodo
	}

	// Es necesario liberar la memoria de cada nodo individualmente
	
	t_node	*temp;			// declaramos un puntero tenmporal para ir liberando la memoria
	
	current = root;			// volvemos a apuntar al primer nodo
	while (current)			// verificamos que current no es NULL
	{
		temp = current->next;	// guardamos la referencia al siguiente nodo
		free(current);			// liberamos el nodo actual
		current = temp;			// avanzamos al siguiente nodo
	}

	return (0);
}