/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:21:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/17 12:29:36 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief First phase of K-sort algorithm: distributes elements from A to B.
 * Distribution strategy:
 * - Case 1: index <= i -> pb + rb.
 * - Case 2: index <= i + range -> pb.
 * - Case 3: else -> ra.
 * @param stack_a Double pointer to the head of the stack A.
 * @param stack_b Double pointer to the head of the stack B.
 * @param range Dynamic value for element distribution.
 * @note i starts at 0 and increases as elements are processed.
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
 * @brief Executes optimal rotation path for K-sort phase 2.
 * Chooses between (rb) and (rrb) based on rotation count comparison:
 * - Uses (rb) if rotate <= reverse.
 * - Uses (rrb) otherwise.
 * @param reverse Number of reverse rotations (rrb) needed.
 * @param rotate Number of normal rotations (rb) needed.
 * @param stack_b Double pointer to head of stack B.
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

/**
 * @brief Second phase of K-sort: reinserts elements from B to A in sorted order.
 * Process per element:
 * - Find max index in stack B.
 * - Calculates optimal rotation path.
 * - Executes rotations via k_sort_step2_aux()
 * - Pushes element to stack A.
 * - Size decreases after each push.
 * @param stack_a Double pointer to the head of the stack A.
 * @param stack_b Double pointer to the head of the stack B.
 * @param size Current number of elements in stack B.
 */
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
 * @brief Main controller for K-sort algorithm.
 * Execution flow:
 * - Assigns positional indexes to values.
 * - Calculates range as square root of size multiply 1.3.
 * - Executes phase 1 (distribution).
 * - Executes phase 2 (reinsertion).
 * @param stack Double pointer to the head of the stack A.
 * @param stack_b Double pointer to the head of the stack B.
 * @param size Total number of elements to sort.
 * @note Optimized for large stacks (>100 elements).
 */
void	k_sort(t_stack **stack, t_stack **stack_b, int size)
{
	int	range;

	add_correct_index(stack, size);
	range = ft_sqroot(size) * (13 / 10);
	k_sort_step1(stack, stack_b, range);
	k_sort_step2(stack, stack_b, size);
}
