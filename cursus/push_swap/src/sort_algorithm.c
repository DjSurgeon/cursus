/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:21:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/15 17:58:20 by sergio-jime      ###   ########.fr       */
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

static void	add_correct_index(t_stack **stack, int size)
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
/**
 * K-sort general
 */
void	k_sort(t_stack **stack, t_stack **stack_b, int size)
{
	int	range;
	int	i;

	i = 0;
	add_correct_index(stack, size);
	range = 2;
	while (*stack)
	{
		if ((*stack)->index <= i)
		{
			ps_push_b(stack, stack_b, true);
			ps_rotate_b(stack_b, true);
			i++;
		}
		else if ((*stack)->index <= i + range)
		{
			ps_push_b(stack, stack_b, true);
			i++;
		}
		else
			ps_rotate_a(stack, true);
	}
}
