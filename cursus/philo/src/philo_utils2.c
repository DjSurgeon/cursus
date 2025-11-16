/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:24:36 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 23:05:55 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_utils2.c
 * @brief Contains essential utility functions (libft style) for the
 * Philosophers project, including string conversion, and character checks.
 */
#include "philo.h"

/**
 * @brief Converts a string to a long integer (ASCII to Long).
 * Parses the initial portion of a string and converts it to a standard
 * `long` integer type, handling optional leading whitespace and sign
 * character. This function is critical for safely checking command-line
 * arguments against potential overflow before they are stored as `int`s in
 * the simulation structure.
 * @param str Null-terminated string to convert.
 * @return long The converted long integer value.
 * @note Leading whitespace is skipped using @ref ft_isspace.
 * @note Requires the presence of @ref ft_isspace and @ref ft_isdigit.
 */
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
 * @brief Counts the number of significant digits in a string representation
 * of a number.
 * This function is designed to measure the true length of the numeric part of
 * a string, skipping any optional sign ('+' or '-') and all leading zeros.
 * This is typically used in conjunction with `ft_atol` to perform a secondary
 * validation check for potential overflows.
 * @param s The string containing the number.
 * @return int The count of significant digits (excluding leading zeros).
 * @note A number like "  +00420" returns 3 (for '4', '2', '0').
 * @note Requires the presence of @ref ft_isdigit.
 */
int	ft_countstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	while (ft_isdigit(s[i]))
	{
		i++;
		count++;
	}
	return (count);
}
