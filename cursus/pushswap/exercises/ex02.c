/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:03:50 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/05 15:57:49 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercises.h"

// void add_front(t_node **head, t_node *new_node);

void	add_front(t_node **head, t_node *new_node)
{
	if (!head || !new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
}

int	main(void)
{
	t_node	*node1;
	t_node	*node2;

	node1 = create_node(10);
	node2 = create_node(20);

	printf("[INT] Node1.value = %d Node1.next = %p", node1->value, node1->value);

	return (0);
}
