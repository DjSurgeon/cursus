/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:03:18 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/08/27 18:05:46 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Frees all nodes and their contents in the token linked list.
 * It correctly deallocates the deep copies of the token values and the nodes
 * themselves.
 * @param tokens A double pointer to the head of the 't_token' list.
 */
void	free_tokens(t_token **tokens)
{
	t_token	*current;
	t_token	*next;

	if (!tokens || !*tokens)
		return ;
	current = *tokens;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	*tokens = NULL;
}

/**
 * @brief Adds a new token node to the end of the token linked list.
 * @param head A pointer to a pointer of the first node in the list.
 * @param new_node A pointer to the new 't_token' node.
 * @note This function does not return a value. It is responsible for
 * manipulating pointers to links the nodes together.
 */
void	lstaddback_token(t_token **head, t_token *new_node)
{
	t_token	*current;

	if (!head || !new_node)
		return ;
	new_node->next = NULL;
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
 * @brief Creates a new token for the lexer's linked list.
 * This function allocates and initialize a new 't_token' node.
 * It takes the string value and the token type as input.
 * The 'type' is directly assigned as it is an enum.
 * @param value The string that represents the token's literal value.
 * @param type The enumerated type of the token.
 * @return t_token* A pointer to tghe newly created 't_token' node.
 * Returns NULL if the input 'value' is 'NULL' or if mempry alocation
 * fails at any point.
 */
t_token	*lstnew_token(char *value, t_token_type type)
{
	t_token	*node;

	if (!value)
		return (NULL);
	node = malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->value = ft_strdup(value);
	if (!node->value)
		return (free(node), NULL);
	node->type = type;
	node->next = NULL;
	return (node);
}
