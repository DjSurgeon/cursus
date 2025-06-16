/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:21:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/16 16:40:17 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * envio al stack b
 */
static void	k_sort_step1(t_stack **stack_a, t_stack **stack_b, int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			ps_push_b(stack_a, stack_b, true);
			ps_rotate_b(stack_b, true);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			ps_push_b(stack_a, stack_b, true);
			i++;
		}
		else
			ps_rotate_a(stack_a, true);
	}
}

/**
 * envia al stack a ordenado
 */
static void	k_sort_step2_aux(int reverse, int rotate, t_stack **stack_b)
{
	int	i;

	i = 0;
	if (rotate <= reverse)
	{
		while (i < rotate)
		{
			ps_rotate_b(stack_b, true);
			i++;
		}
	}
	else
	{
		while (i < reverse)
		{
			ps_reverse_b(stack_b, true);
			i++;
		}
	}
}

static void	k_sort_step2(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	index;
	int	rotate;
	int	reverse;

	while (*stack_b)
	{
		index = max_stack_index(stack_b);
		rotate = rb_count(stack_b, index);
		reverse = size - rotate;
		k_sort_step2_aux(reverse, rotate, stack_b);
		ps_push_a(stack_a, stack_b, true);
		size--;
	}
}

/**
 * K-sort general
 */
void	k_sort(t_stack **stack, t_stack **stack_b, int size)
{
	int	range;

	add_correct_index(stack, size);
	range = ft_sqroot(size) * (13 / 10);
	k_sort_step1(stack, stack_b, range);
	k_sort_step2(stack, stack_b, size);
}
