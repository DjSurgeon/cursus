/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:21:46 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/07 11:02:34 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercises.h"

int	main(void)
{
	t_node	*node1;
	t_node	*node2;

	node1 = create_node(10);
	node2 = create_node(20);

	printf("[INT] Node1.value = %d\n[POINTER]Node1.next = %p\n", node1->value, node1->next);
	printf("[INT] Node2.value = %d\n[POINTER]Node2.next = %p\n", node2->value, node2->next);

	printf("______\n");

	various_nodes	*node10;
	various_nodes	*node20;

	node10 = create_3("hi!", 42, 5.5);
	node20 = create_3("hola", 655, 789.456);

	printf("[CHAR*] Node10.string = %s\n[INT] Node10.value = %d\n[DOUBLE] Node10.dooble = %f\n", node10->string, node10->value, node10->dooble);
	printf("[CHAR*] Node20.string = %s\n[INT] Node20.value = %d\n[DOUBLE] Node20.dooble = %f\n", node20->string, node20->value, node20->dooble);

	return (0);
}
