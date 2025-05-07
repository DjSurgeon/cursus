/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:42:10 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/07 13:22:34 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "exercises.h"

 int	main(void)
 {
	t_node	*head;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;

	head = NULL;
	node1 = create_node(10);
	node2 = create_node(20);
	node3 = create_node(30);
	node4 = create_node(40);
	node5 = create_node(50);

	printf("Node1 -> Value: %d Pointer: %p\n", node1->value, node1->next);
	printf("Node2 -> Value: %d Pointer: %p\n", node2->value, node2->next);
	printf("Node3 -> Value: %d Pointer: %p\n", node3->value, node3->next);

	add_back(&head, node1); // primer nodo
	add_back(&head, node2);	// segundo nodo
	add_back(&head, node3);	// tercer nodo
	printf("Node1 -> Value: %d Pointer: %p\n", node1->value, node1->next);
	printf("Node2 -> Value: %d Pointer: %p\n", node2->value, node2->next);
	printf("Node3 -> Value: %d Pointer: %p\n", node3->value, node3->next);

	// while (tmp != NULL)
	// {
	// 	printf("Value: %d Pointer: %p ->", tmp->value, tmp->next);
	// 	tmp = tmp->next;
	// }

	add_front(&head, node4); // primer nodo ahora
	printf("Node4 -> Value: %d Pointer: %p\n", node4->value, node4->next);
	add_back(&head, node5);	// quinto nodo
	printf("Node4 -> Value: %d Pointer: %p\n", node5->value, node5->next);
	t_node	*tmp;
	tmp = head;

	while (tmp != NULL)
	{
		printf("Value: %d Pointer: %p ->", tmp->value, tmp->next);
		tmp = tmp->next;
	}
	return (0);
 }
