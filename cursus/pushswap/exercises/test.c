/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:21:46 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/05 16:23:47 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercises.h"

int	main(void)
{
	t_node	*node1;
	t_node	*node2;

	node1 = create_node(10);
	node2 = create_node(20);

	printf("[INT] Node1.value = %d Node1.next = %p\n", node1->value, node1->next);
	printf("[INT] Node2.value = %d Node2.next = %p\n", node2->value, node2->next);

	return (0);
}
