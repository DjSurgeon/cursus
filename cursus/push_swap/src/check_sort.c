/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:20:25 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/10 11:56:26 by serjimen         ###   ########.fr       */
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
 *
 */
static void	sort_four(t_stack **stack)
{
	int		max;
	int		size;
	t_stack	*stack_b;

	stack_b = NULL;
	size = stack_size(stack);
	if (!stack || !(*stack))
		return ;
	while (size > 3)
	{
		ps_push_b(stack, &stack_b, true);
		size = stack_size(stack);
	}
	sort_three(stack);
	max = max_value_stack(stack);
	ps_push_a(stack, &stack_b, true);
	if ((*stack)->value > max)
		ps_rotate_a(stack, true);
	else if ((*stack)->value > (*stack)->next->value && (*stack)->value < (*stack)->next->next->value)
		ps_swap_a(stack, true);
	else if ((*stack)->value > (*stack)->next->value && (*stack)->value < max)
	{
		ps_reverse_a(stack, true);
		ps_swap_a(stack, true);
		ps_rotate_a(stack, true);
		ps_rotate_a(stack, true);
	}
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
		sort_four(stack);
	return (true);
}
