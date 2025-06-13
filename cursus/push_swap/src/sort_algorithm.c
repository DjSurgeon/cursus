/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:21:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/12 14:22:51 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * funcion para colocar los indice correctos
 */

void	add_correct_index(t_stack **stack)
{
	t_stack *temp;
	int		*array;
	int		size;
	int		i;

	size = stack_size(stack);
	temp = *stack;
	array = malloc(sizeof(int) * size);
	if (!array)
		return ;
	i = 0;
	while (temp)
	{
		array[i] = temp->value;
		temp = temp->next;
		i++;
	}
}
