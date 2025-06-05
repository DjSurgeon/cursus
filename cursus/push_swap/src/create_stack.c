/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:49:30 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/05 13:33:36 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Function to create a node.
 * @param value The int value.
 * @return The node with the value->value and next->NULL.
 */
static t_stack	*ft_ps_newint(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

/**
 * @brief Function to append the node at the end of the linked list.
 * @param head A pointer to the head of the list.
 * @param new_node The node to append.
 */
static void	ft_ps_addback(t_stack **head, t_stack *new_node)
{
	t_stack	*current;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

t_stack	*create_stack(char **array)
{
	t_stack	*new_node;
	t_stack	*stack;
	int		i;
	long	value_long;
	int		value;

	stack = NULL;
	i = 0;
	while (array[i] != NULL)
	{
		value_long = ft_atol(array[i]);
		value = (int)value_long;
		new_node = ft_ps_newint(value);
		if (!new_node)
		{
			free_stack(&stack);
			free_array(array);
			return (NULL);
		}
		ft_ps_addback(&stack, new_node);
		i++;
	}
	return (stack);
}
