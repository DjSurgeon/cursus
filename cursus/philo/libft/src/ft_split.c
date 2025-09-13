/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:53:37 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/23 13:44:06 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_split.c
 * @brief Frees a partially filled string array.
 * Safety deallocates memory for a string array and its contents up to a
 * specified index. Designed to clean up partially populated arrays during
 * error handling.
 * @note Handles NULL array pointers safely.
 * @note Frees all strings up to index j, then frees the array itself.
 * @param array The string array to free (may be NULL).
 * @param j Number of populated elements to free (0-based index).
 * @warning j should not exceed actual array size.
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
 * @file ft_split.c
 * @brief Populates an array with substrings from a delimited string.
 * Processes the input string to extract words separated by the delimiter
 * and stores them in the pre-allocated array. Each word is allocated
 * as a new null-terminated string.
 * @note Ensures the resulting array is NULL-terminated.
 * @note Performs complete cleanup on allocation failure.
 * @param array Pre-allocated string array to fill.
 * @param s The source string to process (null-terminated).
 * @param c The delimiter character (ASCII value).
 * @param words Number of words expected (from count_words()).
 * @return int 1 on success, 0 on memory allocation failure.
 * @warning The array must be pre-allocated with sufficient size (words+1).
 * @warning The source string must be null-terminated.
 */
static int	fill_words(char **array, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words)
	{
		word_len = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			word_len++;
			i++;
		}
		if (word_len > 0)
			array[j] = ft_substr(s, i - word_len, word_len);
		if (!array[j])
			return (ft_free(array, j), 0);
		j++;
	}
	array[j] = NULL;
	return (1);
}

/**
 * @file ft_split.c
 * @brief Count words in a string separated by a delimiter.
 * Scans the input string and count segment (words) separaated by
 * the specified delimiter character. A word is defined as any sequence
 * of non-delimiter character bounded by delimiter or string ends.
 * @note Empty string between delimiters count as separate words.
 * @note Leading/trailing delimiters are properly handled.
 * @param s The string to analize (null-terminated).
 * @param c The delimiter character (ASCII value).
 * @return size_t Number of word found in the string.
 * @warning Returns 0 if input string is NULL.
 */
static size_t	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;
	int		is_in_word;

	words = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		is_in_word = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (is_in_word == 0)
			{
				words++;
				is_in_word = 1;
			}
			i++;
		}
	}
	return (words);
}

/**
 * @file ft_split.c
 * @brief Splits a string into an array of substrings using a delimiter.
 * Divides the input string into multiple substrings (words) separated
 * by the specified delimiter character. The resulting array is always
 * NULL-terminated.
 * @note The returned array and all strings must be freed by the caller.
 * @note Consecutive delimiter are treated as separate words.
 * @note Empty strings between delimiters are included as empty strings.
 * @param s The string to split (null-terminated).
 * @param c The delimiter character (included in ASCII value).
 * @return char** On success:  NULL-terminated array of strings, on
 * failure: NULL.
 * @warning Caller must free both the array and its strings.
 * @warning Returns NULL if input is NULL or allocation fails.
 * @code
 * // Example
 * char **parts = ft_split("hello,world,42", ',');
 * if (parts)
 * {
 * 	for (int i = 0; parts[i]; i++)
 * 	{
 * 		ft_printf("Part %d: %s\n", i, parts[i]);
 * 		free(parts[i]);
 * 	}
 * 	free(parts);
 * }
 * @endcode
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
