/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:11:11 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/28 10:18:38 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * Iterates through the string 's' to determine the number of characters
 * it contains, excluding the terminating null byte ('\0').
 *
 * @param s A pointer to the string to be measured.
 * @return The number of characters in the string. If 's' is NULL, returns 0.
 */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*start;

	if (!s)
		return (0);
	start = s;
	while (*s != '\0')
		s++;
	return (s - start);
}
