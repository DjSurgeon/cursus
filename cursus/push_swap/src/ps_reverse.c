/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:32:25 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/07 17:10:03 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shifts all the elements of the stack A down one position.
 * The last element become the first.
 * Does nothing if the stack is empty or has only one element.
 * @param stack Pointer to the top of the stack A.
 * @param print Print rra\n if is necessary.
 */

void	ps_reverse_a(t_stack **stack, bool print)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	if (print)
		ft_putstr_fd("rra\n", 1);
}
/**
 * @brief Shifts all the elements of the stack B down one position.
 * The last element become the first.
 * Does nothing if the stack is empty or has only one element.
 * @param stack Pointer to the top of the stack B.
 * @param print Print rrb\n if is necessary.
 */

void	ps_reverse_b(t_stack **stack, bool print)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}
/**
 * @brief Shifts all the elements of the stack A down one position.
 * The last element become the first.
 * Does nothing if the stack is empty or has only one element.
 * @param stack_a Pointer to the top of the stack A.
 * @param stack_b Pointer to the top of the stack B.
 */

void	ps_reverse_rr(t_stack **stack_a, t_stack **stack_b)
{
	ps_reverse_a(stack_a, false);
	ps_reverse_b(stack_b, false);
	ft_putstr_fd("rra\n", 1);
}
