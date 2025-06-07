/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:17:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/07 18:19:20 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack **stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

bool	is_sort(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}
