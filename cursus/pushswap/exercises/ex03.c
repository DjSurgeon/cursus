/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:23:44 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/07 12:45:44 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercises.h"

void	add_back(t_node **head, t_node *new_node)
{
	t_node	*current;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	/* 3) Recorrer la lista hasta el último nodo */
	current = *head;
	while (current->next != NULL)
		current = current->next;
	/* 4) Enlazar el nuevo nodo al final */
	current->next = new_node;
}

