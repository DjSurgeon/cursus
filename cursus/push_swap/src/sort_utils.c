/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:17:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/17 11:33:21 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the position (index) of the minimum value in the stack.
 * @param stack Double pointer to the head of the stack.
 * @return The index position (0-based) of the minimum value in the stack.
 * @note Returns EXIT_FAILURE if stack is NULL or empty.
 * @note The position refers to the node's sequential order (0 = head).
 */
int	min_stack_value(t_stack **stack)
{
	int		min;
	int		i;
	int		index;
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
 * @brief Counts the number of rotations needed to bring a target index
 * to the top.
 * @param stack Double pointer to the head of the stack.
 * @param index Target index to locate.
 * @return Number of rotations (rb) needed, or -1 if index not found.
 */
int	rb_count(t_stack **stack, int index)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->index == index)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

/**
 * @brief Finds the maximum index value present in the stack.
 * @param stack Double pointer to the head of the stack.
 * @return The highest index value found in the stack.
 */
int	max_stack_index(t_stack **stack)
{
	t_stack	*temp;
	int		index;

	temp = *stack;
	index = 0;
	while (temp)
	{
		if (temp->index > index)
			index = temp->index;
		temp = temp->next;
	}
	return (index);
}

/**
 * @brief Calculate the number of elements in the stack.
 * @param stack Double pointer to the head of the stack.
 * @return The total number of elements in the stack.
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
 * @brief Prints detailed information about each node in the stack.
 * Prints for each node:
 * - Index value.
 * - Numeric value.
 * - Memory address of the next node.
 * @param head Pointer to the head node of the stack.
 * @note Outputs "NULL List" if stack is empty.
 * @note Debug function to explain the algorithm, content and structures.
 * @note The output format is designed for debugging linked list integrity.
 */
void	ft_ps_printlist(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		ft_printf("NULL List");
	temp = head;
	while (temp != NULL)
	{
		ft_printf("[index][%d]\t |\t |\n", (int)temp->index);
		ft_printf("\t|[value][%d]\t |\n", temp->value);
		ft_printf("\t|\t |\t[pointer][%p]\n", temp->next);
		temp = temp->next;
	}
	ft_printf("\n");
}
