/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:17:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/16 13:42:58 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * calcula el valor minimo del stack y le asigna un indice
 */
size_t	min_stack_value(t_stack **stack)
{
	int		min;
	int		i;
	size_t	index;
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
			index = (size_t)i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

/**
 * rb count
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
 * calcula el mayor indice del stack.
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