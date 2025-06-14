/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:52:22 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/15 23:52:47 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Bubble Sort;
 */

static int	*bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = i + 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

/**
 * funcion para asignar indice segun valor
 */

static int	find_index(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * funcion para colocar los indice correctos
 */

void	add_correct_index(t_stack **stack, int size)
{
	t_stack	*temp;
	int		*array;
	int		i;

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
	array = bubble_sort(array, size);
	temp = *stack;
	while (temp)
	{
		temp->index = find_index(array, size, temp->value);
		temp = temp->next;
	}
	free(array);
}
