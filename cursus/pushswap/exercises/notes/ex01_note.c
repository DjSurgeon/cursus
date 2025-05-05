/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01_note.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:42:19 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/05 15:54:53 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* -------------------------------------------------------------------------- */
/* Definición de estructuras de datos (nodos)                                  */
/* -------------------------------------------------------------------------- */

// Nodo que almacena un valor entero y un puntero al siguiente nodo.
typedef struct		s_node
{
	int				value;   // Valor almacenado en el nodo
	struct s_node	*next;   // Puntero al siguiente nodo de la lista
}					t_node;

// Nodo que almacena una cadena (char *) y el puntero al siguiente nodo.
typedef struct		ss_node
{
	char			*string; // Cadena de texto almacenada
	struct ss_node	*next;   // Puntero al siguiente nodo
}					string_node;

// Nodo que almacena múltiples campos de distinto tipo.
typedef struct		sss_node
{
	char			*string;  // Cadena
	int				value;    // Entero
	double			dooble;   // Valor de punto flotante (double)
	struct sss_node	*next;    // Puntero al siguiente nodo
}					various_nodes;

/* -------------------------------------------------------------------------- */
/* Funciones de creación de nodos                                              */
/* -------------------------------------------------------------------------- */

/**
 * create_node
 * ------------
 * Reserva memoria dinámica para un nodo de tipo t_node,
 * inicializa sus campos "value" y "next", y devuelve
 * un puntero al nuevo nodo.
 *
 * @param value: entero a almacenar en el nodo.
 * @return: puntero al nodo recién creado, o NULL si malloc falla.
 */

t_node	*create_node(int value)
{
	t_node *node;

	// 1. Reservamos memoria para un nodo de tamaño sizeof(t_node)
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);  // Verificación de fallo en malloc

	// 2. Asignamos el valor recibido y establecemos next en NULL
	node->value = value;
	node->next = NULL;
	return (node);
}

/**
 * create_s_node
 * -------------
 * Similar a create_node, pero para nodos que almacenan cadenas.
 */

string_node	*create_s_node(char *str)
{
	string_node	*node;

	node = malloc(sizeof(string_node));
	if (!node)
		return (NULL);
	node->string = str;
	node->next = NULL;
	return (node);
}

/**
 * create_3
 * --------
 * Crea un nodo "various_nodes" que contiene tres campos diferentes.
 */

various_nodes	*create_3(char *s, int i, double d)
{
	various_nodes	*my_node;

	my_node = malloc(sizeof(various_nodes));
	if (!my_node)
		return (NULL);
	my_node->string = s;
	my_node->value = i;
	my_node->dooble = d;
	my_node->next = NULL;
	return (my_node);
}

/* -------------------------------------------------------------------------- */
/* Ejemplos de uso en main                                                     */
/* -------------------------------------------------------------------------- */

int	main(void)
{
	// 1. Crear nodos de diferentes tipos
	t_node         *new_node_int;
	t_node         *node3;
	string_node    *s_node1;
	string_node    *s_node2;
	various_nodes  *my_node1;

	// Creamos dos nodos enteros con valores distintos
	new_node_int = create_node(1940);
	node3        = create_node(561);

	// Imprimimos su contenido y comprobamos que "next" apunta a NULL
	printf("[INT] valor: %d, next: %p\n", new_node_int->value, new_node_int->next);
	printf("[INT] valor: %d, next: %p\n", node3->value, node3->next);

	// Creamos dos nodos de cadenas
	s_node1 = create_s_node("Hello!!");
	s_node2 = create_s_node("Bonjour 42!");

	// Imprimimos las cadenas almacenadas
	printf("[STR] %s\n", s_node1->string);
	printf("[STR] %s\n", s_node2->string);

	// Creamos un nodo con múltiples campos
	my_node1 = create_3("Hola", 42, 5.72);
	printf("[MIX] String: %s, Int: %d, Double: %f, next: %p\n",
	       my_node1->string, my_node1->value, my_node1->dooble, my_node1->next);

	/*
	 * Nota: Este ejercicio sólo crea nodos, pero no construye la lista.
	 * Para unir nodos y formar la lista enlazada, se usarían campos "next",
	 * por ejemplo:
	 *    new_node_int->next = node3;
	 * Esto haría que new_node_int apunte a node3.
	 */

	// 2. Liberación de memoria (si se quisiera limpiar manualmente)
	free(new_node_int);
	free(node3);
	free(s_node1);
	free(s_node2);
	free(my_node1);

	return (0);
}
