/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:20:00 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/22 19:39:21 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strchr.c
 * @brief Locates first occurrence of character in string.
 * Scans the null-terminated string 's' for the first occurrence of character
 * 'c' (converted to char). The search includes the terminating null character,
 * allowing for null-character searches.
 * @param s Null-terminated stringto search.
 * @param c Character to locate (converted to char).
 * @return char* Pointer to the located character in 's', or NULL if the
 * character
 */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len]);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
