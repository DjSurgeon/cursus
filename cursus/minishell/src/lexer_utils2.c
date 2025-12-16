/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:10:15 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/09/01 12:42:56 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file lexer_utils2.c
 * @brief Utility functions for handling token lists as arrays.
 */
#include "minishell.h"

/**
 * @brief Calculates the number of nodes in a token linked list.
 * @param lst A pointer to the head of the 't_token' list.
 * @return size_t The number of nodes in the list.
 */
static size_t	lstsize_token(t_token *lst)
{
	size_t	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

/**
 * @brief Converts a token linked list into a dynamically allocated array
 * of strings.
 * This function creates a deep copy of the token values from a linked list.
 * @param tokenlist The head of the 't_token' linked list to be converted.
 * @return char** Return a new dynamically allocated, NULL-terminated array
 * of strings. Returns NULL if memory allocation fails at any point.
 * @note The use of 'ft_strdup' is a critical design choice here. It prevents
 * the new array from holding pointers to the original token list's memory,
 * which would lead to dangling pointers if the list were to be freed before
 * the array.
 */
char	**tokenlist_to_arr(t_token *tokenlist)
{
	t_token	*temp;
	char	**tokenarr;
	size_t	count;
	size_t	i;

	count = lstsize_token(tokenlist);
	tokenarr = ft_calloc(count + 1, sizeof(char *));
	if (!tokenarr)
		return (NULL);
	temp = tokenlist;
	i = 0;
	while (temp)
	{
		tokenarr[i] = ft_strdup(temp->value);
		if (!tokenarr[i])
			return (ft_free_array(tokenarr), NULL);
		temp = temp->next;
		i++;
	}
	tokenarr[i] = NULL;
	return (tokenarr);
}
