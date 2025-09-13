/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:37 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/22 18:41:56 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strjoin.c
 * @brief Concatenates two strings into a new dinamically allocated string.
 * Allocates memory for and creates a new string that is the result of
 * concatenating string s1 followed by string s2. The new string is
 * null-terminated and memory is using allocated using ft_calloc.
 * @note The returned string must be freed by the caller when no longer
 * needed.
 * @note If either s1 or s2 is NULL, treats it as an empty string ("").
 * @param s1 First null-terminated string to concatenate (can be NULL).
 * @param s2 Second null-terminated string to concatenate (can be NULL).
 * @return char* On success: Pointer to newly allocated concatenated string.
 * On failure: NULL (memory allocation failed).
 * @code
 * // Example
 * char *result = ft_strjoin("Hello ", "World");
 * if (result)
 * {
 * 	ft_printf("%s\n", result); // Output: "Hello World"
 * free(result);
 * }
 * @endcode
 */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	j = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new_string = ft_calloc(1, size_s1 + size_s2 + 1);
	if (!new_string)
		return (NULL);
	while (i < size_s1)
	{
		new_string[i] = s1[i];
		i++;
	}
	while (j < size_s2)
	{
		new_string[i + j] = s2 [j];
		j++;
	}
	return (new_string);
}
