/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:42:19 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/05 16:20:43 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Declaración de la estructura que almacena los nodos
// Esta primera estructura va a almacenar valores de int

typedef struct		s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

// Esta estructura puede almacenar string

typedef struct		ss_node
{
	char*			string;
	struct ss_node	*next;
}					string_node;

// Esta estructura almacena varios valores

typedef struct		sss_node
{
	char*			string;
	int				value;
	double			dooble;
	struct sss_node	*next;
}					various_nodes;

// Estas funciones crean nodos dependiendo de la estructura y los valores

t_node	*create_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

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
/*
int	main(void)
{
	int	value;
	t_node *new_node;
	t_node *node3;
	string_node *s_node1;
	string_node *s_node2;
	various_nodes *my_node1;

	value = 9;
	new_node = create_node(1940);
	node3 = create_node(561);
	printf("valor: %d\n", new_node->value);
	printf("puntero: %p\n ", new_node->next);
	printf("valor: %d\n", node3->value);
	printf("puntero: %p\n", node3->next);

	s_node1 = create_s_node("Hello!!");
	s_node2 = create_s_node("Bonjour 42!");
	printf("%s\n", s_node1->string);
	printf("%s\n", s_node2->string);

	my_node1 = create_3("Hola", 42, 5.72);
	printf("String: %s, Int: %d, Boolean: %f\n", my_node1->string, my_node1->value, my_node1->dooble);
	return (0);
}
 */
