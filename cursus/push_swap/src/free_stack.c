/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:53:23 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/17 12:37:02 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Deallocates all nodes in a stack and resets the stack pointer.
 * Iterates through echa node to:
 * - Free node memory.
 * - Set stack head to NULL.
 * @param stack Double pointer to the head of the stack.
 * @note Safe for NULL inputs and already freed stacks.
 */

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
