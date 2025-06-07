/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:20:25 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/07 18:56:38 by sergio-jime      ###   ########.fr       */
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

static void	sort_three(t_stack **stack)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;

	one = *stack;
	if (!one)
		return ;
	two = (*stack)->next;
	three = (*stack)->next->next;
	if (one->value > two->value && two->value < three->value)
		ps_rotate_a(stack, true);
	else if (one->value > two->value && two->value > three->value)
	{
		ps_swap_a(stack, true);
		ps_reverse_a(stack, true);
	}
	else if (one->value < three->value)
	{
		ps_swap_a(stack, true);
		ps_rotate_a(stack, true);
	}
	else if (one->value < two->value)
		ps_reverse_a(stack, true);
	else if (one->value > two->value && one->value > three->value)
		ps_swap_a(stack, true);
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
	return (true);
}
