/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:19:40 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/06 17:27:56 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Moves the first element on top of stack A and puts it on top
 * of stack B.
 * Print pb\n if is necessary.
 * @param stack_a Pointer to the top of the stack A.
 * @param stack_b Pointer to the top of the stack B.
 * @param print Check if is necessary print the movement.
 */

void	ps_push_b(t_stack **stack_a, t_stack **stack_b, bool print)
{
	t_stack	*node_to_move;

	if (!stack_a || !*stack_a)
		return ;
	node_to_move = *stack_a;
	*stack_a = (*stack_a)->next;
	node_to_move->next = *stack_b;
	*stack_b = node_to_move;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
/**
 * @brief Moves the first element on top of stack B and puts it on top
 * of stack A.
 * Print pb\n if is necessary.
 * @param stack_a Pointer to the top of the stack A.
 * @param stack_b Pointer to the top of the stack B.
 * @param print Check if is necessary print the movement.
 */

void	ps_push_a(t_stack **stack_a, t_stack **stack_b, bool print)
{
	t_stack	*node_to_move;

	if (!stack_b || !*stack_b)
		return ;
	node_to_move = *stack_b;
	*stack_b = (*stack_b)->next;
	node_to_move->next = *stack_a;
	*stack_a = node_to_move;
	if (print)
		ft_putstr_fd("pa\n", 1);
}
