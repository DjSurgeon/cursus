/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:43:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/22 16:20:49 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnstr.c
 * @brief Locates the first occurrence of a substring with length limit.
 * Searches for the first ocurrence of the null-terminated string 'little'
 * in the string 'big' where not more than 'len' characters are searched.
 * Characters that appear after a ('\0') character are not searched.
 * @note Safe for NULL inputs.
 * @note Comparison stops at first null terminator encountered.
 * @param big The string to be scanned (haystack).
 * @param little The string to search for (needle).
 * @param len Maximum number of characters to search in 'big'.
 * @return char* If 'little' is empty, returns 'big'.
 * If 'little' occurs nowhere in 'big', returns NULL.
 * Otherwise returns pointer to first character of the first occurrence
 * of 'little' within 'big'.
 * @code
 * // Example:
 * char *found = ft_strnstr("Hello world", "wor", 11);
 * // returns pointer to "world"
 * char *notfound = ft_strnstr("Hello", "world", 5);
 * // returns NULL
 * @endcode
 */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
