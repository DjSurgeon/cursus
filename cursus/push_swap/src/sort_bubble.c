/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:52:22 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/17 11:49:21 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts an integer array using bubble sort algorithm.
 * @param array Pointer to the integer array to be sorted.
 * @param size Number of elements in the array.
 * @return Pointer to the sorted array (same memory location).
 * @note Performs in-place sorting with O(n²) time complexity.
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
 * @brief Find the position index of a value in a sorted array.
 * @param array Pointer to the sorted integer array.
 * @param size Number of elements in the array.
 * @param value The integer value to locate.
 * @return The 0-based index position of the value, or -1 if not found.
 * @note Uses linear search; array must be sorted for meaningful results.
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
 * @brief Assigns positional indexes to stack nodes based on their values.
 * Process:
 * - Copies stack values to a temporary array.
 * - Sorts the array using bubble sort.
 * - Assigns each node's index based on its position in the sorted array.
 * @param stack Double pointer to the head of the stack.
 * @param size Number of elements in the stack.
 * @note Allocates and frees temporary memory; handles NULL stack safely.
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
