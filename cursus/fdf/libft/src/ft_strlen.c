/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:11:11 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/22 09:17:01 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlen.c
 * @brief Calculates the length of a null-terminated string.
 * Computes the number of characters in the string pointed to by 's',
 * excluding the terminating null byte ('\0'). The function iterates through
 * the string until it encounters the null terminator.
 * @note The input string must be properly null-terminated.
 * @note Returns 0 if NULL pointer is passed.
 * @note Safe for read-only strings.
 * @param s Pointer to the null-terminated string to measure.
 * @return size_t The number of characters in the string preceding the null
 * terminator.
 */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
