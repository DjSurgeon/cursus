/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:20:25 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/18 10:15:02 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the stack is sorted in ascending order.
 * @param stack Double pointer to the head of the stack.
 * @return True if the stack is sorted, false otherwise.
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
/**
 * @brief Sorts a stack of two elements.
 * Performs a swap operation (sa) if the first element is greater
 * than the second.
 * @param stack Double pointer to the head of the stack.
 */

static void	sort_two(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp || !temp->next)
		return ;
	if (temp->value > temp->next->value)
		ps_swap_a(stack, true);
}
/**
 * @brief Sort a stack of three elements using optimal operations.
 * Analizes the relative positions of values and applies combinations of:
 * - Swap (sa), rotate (ra) or reverse rotate (rra).
 * @param stack Double pointer to the head of the stack.
 */

static void	sort_three(t_stack **stack)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;

	if (!*stack || is_sort(stack))
		return ;
	one = *stack;
	two = (*stack)->next;
	three = (*stack)->next->next;
	if ((one->value > two->value) && (one->value < three->value))
		return (ps_swap_a(stack, true));
	else if ((two->value > one->value) && (one->value < three->value))
		return (ps_swap_a(stack, true), ps_rotate_a(stack, true));
	else if ((two->value > one->value) && (one->value > three->value))
		return (ps_reverse_a(stack, true));
	else if ((one->value > two->value) && (two->value > three->value))
		return (ps_swap_a(stack, true), ps_reverse_a(stack, true));
	else if ((one->value > two->value) && (two->value < three->value))
		return (ps_rotate_a(stack, true));
}

/**
 * @brief Sorts stacks of four or five elements.
 * Strategy:
 * - Find and pushes the smallest values to stack B.
 * - Sorts the remaining three elements in the stack A.
 * - Pushes all the elements back from stack B to stack A.
 * @param stack Double pointer to the head of stack A.
 */
static void	sort_five(t_stack **stack)
{
	int		index;
	t_stack	*stack_b;

	stack_b = NULL;
	if (!stack || !(*stack))
		return ;
	while (stack_size(stack) > 3)
	{
		index = min_stack_value(stack);
		while (min_stack_value(stack) != 0)
		{
			if (index <= (stack_size(stack) / 2))
				ps_rotate_a(stack, true);
			else if (index > (stack_size(stack) / 2))
				ps_reverse_a(stack, true);
		}
		ps_push_b(stack, &stack_b, true);
	}
	sort_three(stack);
	while (stack_b)
		ps_push_a(stack, &stack_b, true);
	free_stack(&stack_b);
}
/**
 * @brief Select the appropiate sorting algorithm based on stack size.
 * Algorith selection:
 * - Size 2: sort_two.
 * - Size 3: sort_three.
 * - Size 4-5: sort_five.
 * - Size >5: k_sort (radix-based algorithm).
 * @param stack Double pointer to the head of the stack A.
 * @param stack_b Double pointer to the head of the stack B.
 * @return True if sorting was successful/initiated, false on error.
 */

bool	check_sort(t_stack **stack, t_stack **stack_b)
{
	int	size;

	if (is_sort(stack))
		return (true);
	size = stack_size(stack);
	if (size == 2)
		sort_two(stack);
	if (size == 3)
		sort_three(stack);
	if (size >= 4 && size <= 5)
		sort_five(stack);
	if (size > 5)
		k_sort(stack, stack_b, size);
	return (true);
}
