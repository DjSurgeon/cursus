/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:05:00 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/23 12:33:59 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_substr.c
 * @brief Create a substring from a portion of a string.
 * Allocates and returns a substring from string 's' starting at index 'start'
 * with maximum length 'len'. The substring is always null-terminated.
 * @note Returns empty string if start is beyond string length.
 * @note Automatically adjusts len if it exceeds remaining characters.
 * @note The returned string must be freed by the caller.
 * @param s Source string (null-terminated).
 * @param start Starting index of substring in 's'.
 * @param len Maximum length of substring.
 * @return char* On success: Newly allocated substring, on failure: NULL.
 * @warning Start position is 0-indexed.
 * @code
 * // Example
 * char *sub1 = ft_substr("Hello World", 6, 5); // sub1 = "World"
 * char *sub2 = ft_substr("Hello", 2, 10); // sub2 = "llo"
 * char *sub3 = ft_substr("Hello", 10, 5); // sub3 = ""
 * char *sub4 = ft_substr(NULL, 2, 2); // sub4 = NULL
 * @endcode
 */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_substring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		new_substring = malloc(1);
		if (!new_substring)
			return (NULL);
		new_substring[0] = '\0';
		return (new_substring);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new_substring = ft_calloc(1, len + 1);
	if (!new_substring)
		return (NULL);
	while (i < len)
	{
		new_substring[i] = s[start + i];
		i++;
	}
	return (new_substring);
}
