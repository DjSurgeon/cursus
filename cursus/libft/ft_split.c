/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:53:37 by serjimen          #+#    #+#             */
/*   Updated: 2026/03/09 02:35:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Frees the allocated memory for the array of strings.
 *
 * This function iterates through the array and frees each allocated string,
 * then frees the array itself.
 *
 * @param array The array of strings to be freed.
 * @param j The number of strings to free.
 */
static void	ft_free(char **array, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * @brief Counts the number of words in a string separated by a delimiter.
 *
 * @param s The string to analyze.
 * @param c The delimiter character.
 * @return The number of words found.
 */
static size_t	count_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

/**
 * @brief Fills the array with substrings from the input string.
 *
 * @param array The array to fill.
 * @param s The input string.
 * @param c The delimiter character.
 * @param words The total number of words to extract.
 * @return 1 on success, 0 on failure (memory allocation).
 */
static int	fill_words(char **array, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len > 0)
		{
			array[j] = ft_substr(s, i, len);
			if (!array[j])
				return (ft_free(array, j), 0);
			j++;
			i += len;
		}
	}
	array[j] = NULL;
	return (1);
}

/**
 * @brief Splits a string into an array of strings using a delimiter.
 *
 * Allocates an array of strings representing the result of splitting 's'
 * with the character 'c'. The array is NULL-terminated.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings, or NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = ft_calloc(words + 1, sizeof(char *));
	if (!result)
		return (NULL);
	if (!fill_words(result, s, c, words))
		return (NULL);
	return (result);
}
