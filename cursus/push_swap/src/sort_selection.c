/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:20:25 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/11 12:21:47 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 */

// static void	reverse_sort_two(t_stack **stack)
// {
// 	t_stack	*temp;

// 	temp = *stack;
// 	if (!temp || !temp->next)
// 		return ;
// 	if (temp->value < temp->next->value)
// 		ps_swap_a(stack, true);
// }

/**
 * Ordena 2
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
 * Ordena 3
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
 * Ordena 5
 */
static void	sort_five(t_stack **stack)
{
	size_t	index;
	t_stack	*stack_b;

	stack_b = NULL;
	if (!stack || !(*stack))
		return ;
	while (stack_size(stack) > 3)
	{
		index = min_stack_value(stack);
		while (min_stack_value(stack) != 0)
		{
			if ((int)index <= (stack_size(stack) / 2))
				ps_rotate_a(stack, true);
			else if ((int)index > (stack_size(stack) / 2))
				ps_reverse_a(stack, true);
		}
		ps_push_b(stack, &stack_b, true);
	}
	sort_three(stack);
	while (stack_b)
		ps_push_a(stack, &stack_b, true);
	free_stack(&stack_b);
}

bool	check_sort(t_stack **stack)
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
	return (true);
}
