/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:17:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/09 18:34:03 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * 
 */
int	min_stack_value(t_stack **stack)
{
	int		min;
	int		index;
	int		i;
	t_stack	*temp;

	if (!stack || !(*stack))
		return (EXIT_FAILURE);
	temp = *stack;
	min = temp->value;
	index = 0;
	i = 0;
	while (temp)
	{
		if (temp->value < min)
		{
			min = temp->value;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

/**
 * @brief Calculate the size of the stack.
 * @param stack Pointer to the head of the stack.
 * @return The size of the stack.
 */
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

/**
 * @brief Verify if the stack is sort.
 * @param stack Pointer to the head of the stack.
 * @return True if the stack is sort.
 */
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
