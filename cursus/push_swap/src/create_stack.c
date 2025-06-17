/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:49:30 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/17 10:39:15 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Creates a new node for the stack with a given integer value
 * and index.
 * This function allocates memory for a new stack node, initializes it with
 * provided value and index, and sets the next pointer to NULL.
 * @param value The integer value to store in the node.
 * @param index The position index of the node in the stack.
 * @return A pointer to the newly created node, or NULL if 
 * memory allocations fails.
 * @note The caller is responsible for freeing the node when it is no
 * longer needed.
 */
static t_stack	*ft_ps_newint(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

/**
 * @brief Appends the node to the en of the stack.
 * This function adds the given node to the end of the linked list representing
 * the stack.
 * If the stack is empty, the new node becomes the head of the stack.
 * @param head A pointer to the pointer of the first node in the stack.
 * @param new_node The node to append to the stack.
 * @note This function does not return a value. It modifies the stack in place.
 * @warning If either head or new_node is NULL, the function does nothing.
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

/**
 * @brief Creates a stack from an array of strings representing integers.
 * This function converts each string in the array to an integer, creates
 * a stack node for each value, and appends it to stack while assigning an index.
 * @param array The array of strings to convert into stack nodes.
 * @return A pointer to the head of the stack, or NULL if an error occurs
 * during conversion or memory allocation.
 * @note The function checks for integer overflow and invalid strings lengths.
 * @note In case of an error, frees the allocated stack and the array.
 * @warning The array must be NULL-terminated.
 */
t_stack	*create_stack(char **array)
{
	t_stack	*new_node;
	t_stack	*stack;
	size_t	i;
	long	value_long;

	stack = NULL;
	i = 0;
	while (array[i] != NULL)
	{
		value_long = ft_atol(array[i]);
		if (value_long > INT_MAX || value_long < INT_MIN)
			return (free_array_c(array), NULL);
		new_node = ft_ps_newint((int)value_long, i);
		if (!new_node)
		{
			free_stack(&stack);
			free_array_c(array);
			return (NULL);
		}
		ft_ps_addback(&stack, new_node);
		i++;
	}
	return (stack);
}
