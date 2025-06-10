/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:20:25 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/10 16:51:36 by sergio-jime      ###   ########.fr       */
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
 * 
 */
static void	sort_four_util(size_t index, t_stack **stack, t_stack **stack_b)
{
	size_t	i;
	int		size;

	temp = *stack;
	size = stack_size(stack);
	i =  index;
	while (size > 3)
	{
		index = min_stack_value(stack);
		while (i < size/2)
		{
			i--;
		}
	}
	if (index == 0)
		ps_push_b(stack, stack_b, true);
	if (index == 1)
	{
		ps_swap_a(stack, true);
		ps_push_b(stack, stack_b, true);
	}
	if (index == 2)
	{
		ps_reverse_a(stack, true);
		ps_reverse_a(stack, true);
		ps_push_b(stack, stack_b, true);
	}
	if (index == 3)
	{
		ps_reverse_a(stack, true);
		ps_push_b(stack, stack_b, true);
	}
}

/**
 * Ordena 4
 */
static void	sort_four(t_stack **stack)
{
	size_t	index;
	t_stack	*stack_b;

	stack_b = NULL;
	if (!stack || !(*stack))
		return ;
	index = min_stack_value(stack);
	sort_four_util(index, stack, &stack_b);
	sort_three(stack);
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
	if (size == 4)
		sort_four(stack);
	return (true);
}
