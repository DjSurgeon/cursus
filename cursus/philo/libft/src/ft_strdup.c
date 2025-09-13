/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:46:15 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/22 18:21:18 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strdup.c
 * @brief Creates a duplicate of a string
 * Allocates memory for and creates a exact copy of the input string,
 * including the null terminator. The new string is allocated using
 * ft_calloc to ensure proper initialization.
 * @note The returned string must be freed by the caller.
 * @note Safe for NULL inputs.
 * @param s Null-terminated string to duplicate (can be NULL)
 * @return char* On success: Pointer to newly allocated string copy,
 * on failure: NULL (memory allocation failed).
 * @code
 * // Example
 * char *original = "Hello";
 * char *duplicate = ft_strdup(original);
 * if (copy)
 * {
 * 	ft_printf("%s\n", copy); // Output: "Hello"
 * 	free(copy);
 * }
 * @endcode
 */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;
	size_t	s_size;
	size_t	i;

	i = 0;
	s_size = ft_strlen(s);
	new_string = ft_calloc(1, s_size + 1);
	if (!new_string)
		return (NULL);
	while (i < s_size)
	{
		new_string[i] = s[i];
		i++;
	}
	return (new_string);
}
