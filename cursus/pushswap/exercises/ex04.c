/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:07:07 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/07 15:14:34 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercises.h"

int list_length(t_node *head)
{
	t_node	*temp;
	int		counter;

	temp = head;
	counter = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}

void	print_list(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}

void	free_list(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
