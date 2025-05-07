/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:05:22 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/07 12:20:27 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercises.h"

int	main(void)
{
	t_node	*head;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*temp;

	head = NULL;
	node1 = create_node(10);
	node2 = create_node(20);
	node3 = create_node(30);

	printf("Values & pointers=====\n");
	printf("Value: %d\nPointer: %p\n", node1->value, node1->next);
	printf("Value: %d\nPointer: %p\n", node2->value, node2->next);
	printf("Value: %d\nPointer: %p\n", node3->value, node3->next);

	add_front(&head, node3);
	add_front(&head, node2);
	add_front(&head, node1);

	printf("Linked list========\n");
	printf("Value: %d\nPointer: %p\n", node1->value, node1->next);
	printf("Value: %d\nPointer: %p\n", node2->value, node2->next);
	printf("Value: %d\nPointer: %p\n", node3->value, node3->next);

	// Recorremos la lista desde head
    printf("Recorriendo la lista:\n");
    temp = head;
    while (temp)
    {
        printf("  Value: %d, Next: %p\n",
               temp->value, (void*)temp->next);
        temp = temp->next;
    }


	return (0);
}
