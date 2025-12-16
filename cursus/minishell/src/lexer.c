/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:33:51 by serjimen          #+#    #+#             */
/*   Updated: 2025/08/27 17:42:32 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @file lexer.c
* @brief Main function for the lexing phase of minishell.
* This file contains the 'tokenizer' function, which is responsible for 
* converting a raw command-line string into a structured linked list of tokens.
* It is the core of the lexer, coordinating the splitting, classification,
* and list-building processes.
 */
#include "minishell.h"

/**
 * @brief Creates a new token based on an operator string.
 * @param str The string representing the operator.
 * @return t_token* A new dynamically allocated 't_token' node  representing
 * the operator. Returns NULL if an unexpected error occurs during token
 * creation.
 */
static t_token	*set_token(char *str)
{
	t_token	*new_token;
	size_t	len;

	len = ft_strlen(str);
	if (len == 2 && ft_strncmp(str, ">>", 2) == 0)
		new_token = lstnew_token(str, APPEND);
	else if (len == 2 && ft_strncmp(str, "<<", 2) == 0)
		new_token = lstnew_token(str, HEREDOC);
	else if (len == 1 && ft_strncmp(str, ">", 1) == 0)
		new_token = lstnew_token(str, REDIR_OUT);
	else if (len == 1 && ft_strncmp(str, "<", 1) == 0)
		new_token = lstnew_token(str, REDIR_IN);
	else if (len == 1 && ft_strncmp(str, "|", 1) == 0)
		new_token = lstnew_token(str, PIPE);
	else
		new_token = NULL;
	return (new_token);
}

/**
 * @brief Checks if a string is a valid minishell operator.
 * @param str The string to be evaluated.
 * @return true If the string matches one of the known operators.
 * @return false Otherwise
 * @note The function correctly handles the case of multi-character
 * operators by checking their length first.
 */
static bool	is_operator(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 2 && ft_strncmp(str, ">>", 2) == 0)
		return (true);
	else if (len == 2 && ft_strncmp(str, "<<", 2) == 0)
		return (true);
	else if (len == 1 && ft_strncmp(str, ">", 1) == 0)
		return (true);
	else if (len == 1 && ft_strncmp(str, "<", 1) == 0)
		return (true);
	else if (len == 1 && ft_strncmp(str, "|", 1) == 0)
		return (true);
	else
		return (false);
}

/**
 * @brief Classifies a given string and creates a new token node.
 * @param str The string to be classified and converted into a token.
 * @return t_token* A new dynamically allocated 't_token' node.
 * Returns NULL if the input string is invalid of id a memory
 * allocation fails.
 * @note This function is crucial for maintaining a clean and extensible
 * lexer. By separating the classification logic from the token creation
 * process, it allows for easy addition of new token types in the future.
 * The design  adheres to the "deep copy" principle, ensuring the new
 * token node is self-contained and independent of the input string.
 */
static t_token	*classify_tokens(char *str)
{
	t_token	*new_token;

	if (!str)
		return (NULL);
	if (is_operator(str))
		new_token = set_token(str);
	else
		new_token = lstnew_token(str, WORD);
	if (!new_token)
		return (NULL);
	return (new_token);
}

/**
 * @brief Splits a command string, classifies the resulting substring, and
 * builds a linked list of tokens.
 * The function takes a raw command-line string and performs the following
 * steps:
 * 1. It splits the input string into an array of substring based on spaces.
 * 2. It iterates through this array, classifying each substring using the
 * 'classify_tokens' function to determine its type.
 * 3. It creates a new 't_token' node for each classified token.
 * 4. It appends the new node to the end of a 't_token' linked list.
 * 5. It manages all dynamically allocated memory, ensuring that the temporary
 * array of strings created by 'ft_split' is freed, and that the token list is
 * properly freed in case of an allocation error.
 * @param str The raw command-line string to be tokenized.
 * @return A pointer to the head of the newly created 't_token' linked list.
 * Returns NULL if the input string is invalid or if a memory allocation
 * failure occurs at any point during the process.
 * @note It design with explicit error handling and cleanup, for preventing
 * memory leaks in a long-runnning shell.
 */
t_token	*tokenizer(char *str)
{
	t_token	*tokens_list;
	t_token	*new_token;
	char	**tokens;
	size_t	i;

	tokens_list = NULL;
	if (!str || !*str)
		return (NULL);
	tokens = ft_split(str, ' ');
	if (!tokens)
		return (NULL);
	i = 0;
	while (tokens[i])
	{
		new_token = classify_tokens(tokens[i]);
		if (!new_token)
			return (ft_free_array(tokens), free_tokens(&tokens_list), NULL);
		lstaddback_token(&tokens_list, new_token);
		i++;
	}
	ft_free_array(tokens);
	return (tokens_list);
}
