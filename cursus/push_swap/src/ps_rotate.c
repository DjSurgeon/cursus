/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:09:14 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/06 17:42:32 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shifts all the elements of the stack A up by one position.
 * The first element becomes the last.
 * Does nothing if the stack is empty or has only one element.
 * @param stack Pointer to the top of the stack A.
 * @param print Print ra\n if is necessary.
 */

void	ps_rotate_a(t_stack **stack, bool print)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	*stack = (*stack)->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_putstr_fd("ra\n", 1);
}
/**
 * @brief Shifts all the elements of the stack B up by one position.
 * The first element becomes the last.
 * Does nothing if the stack is empty or has only one element.
 * @param stack Pointer to the top of the stack B.
 * @param print Print ra\n if is necessary.
 */

void	ps_rotate_b(t_stack **stack, bool print)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	*stack = (*stack)->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

/**
 * @brief Shifts all the elements of the stack A up by one position.
 * The first element becomes the last.
 * Does nothing if the stack is empty or has only one element.
 * @param stack Pointer to the top of the stack A.
 * @param print Print ra\n if is necessary.
 */

void	ps_rotate_rr(t_stack **stack_a,t_stack **stack_b)
{
	ps_rotate_a(stack_a, false);
	ps_rotate_b(stack_b, false);
	ft_putstr_fd("rr\n", 1);
}
