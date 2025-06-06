/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:14:38 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/06 14:13:22 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the first two elements of the stack A.
 * The stack need almost two elements to execute the movement.
 * Print sa\n if is necessary.
 * @param stack Pointer to the top of the stack A.
 * @param print Check if is necessary print the movement.
 */

void	ps_swap_a(t_stack **stack, bool print)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	*stack = second;
	second->next = first;
	first->next = third;
	if (print)
		ft_putstr_fd("sa\n", 1);
}
/**
 * @brief Swap the first two elements of the stack B.
 * The stack need almost two elements to execute the movement.
 * Print sb\n if is necessary.
 * @param stack Pointer to the top of the stack B.
 * @param print Check if is necessary print the movement.
 */

void	ps_swap_b(t_stack **stack, bool print)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	*stack = second;
	second->next = first;
	first->next = third;
	if (print)
		ft_putstr_fd("sb\n", 1);
}
/**
 * @brief Swap the first two elements of the stack A and the stack B.
 * The stack need almost two elements to execute the movement.
 * Print ss\n.
 * @param stack_a Pointer to the top of the stack A.
 * @param stack_b Pointer to the top of the stack B.
 */

void	ps_swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	ps_swap_a(stack_a, false);
	ps_swap_b(stack_b, false);
	ft_putstr_fd("ss\n", 1);
}
