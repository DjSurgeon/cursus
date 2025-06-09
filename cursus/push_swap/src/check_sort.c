/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:20:25 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/09 19:03:58 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * 
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
 * 
 */

static void	sort_three(t_stack **stack)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;

	if (!*stack)
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
 * 
 */
static void	sort_five(t_stack **stack)
{
	int		index;
	int		size;
	t_stack	*stack_b;

	index = 0;
	size = 5;
	stack_b = NULL;
	if (!stack || !(*stack))
		return ;
	while (size > 3)
	{
		index = min_stack_value(stack);
		if (index == 0)
			ps_push_b(stack, &stack_b, true);
		else
			ps_reverse_a(stack, true);
		size = stack_size(stack);
	}
	sort_three(stack);
	ps_push_a(stack, &stack_b, true);
	ps_push_a(stack, &stack_b, true);
	free_stack(&stack_b);
}

bool	check_sort(t_stack **stack)
{
	int	size;

	size = 0;
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
