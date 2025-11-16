/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:24:36 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 20:25:14 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	size_t	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

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
 * @code
 * // Example
 * const char *str = "Hello world";
 * size_t len = ft_strlen(str); // len = 11
 * @endcode
 */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
