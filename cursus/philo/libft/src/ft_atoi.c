/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:31:59 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/23 17:36:11 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 * @brief Converts a string to an integer (ASCII to int).
 * Parses the initial portion of a string and converts it to a 32-bit integer,
 * handling optional leading whitespace, an optional sign character (+/-),
 * and numerical digits.
 * @note Leading whitespace is skipped.
 * @note Processes optional single '+' or '-' sign character.
 * @note Stops conversion at first non-digit character.
 * @param str Null-terminated string to convert.
 * @return int The converted integer value.
 * @warning Returns 0 if no valid conversion could be performed.
 * @warning Does not validate NULL pointer input.
 * @warning Behavior is undefined on interger overflows.
 * @warning Only supports base 10 conversion.
 * @code
 * // Example
 * int val1 = ft_atoi("42"); // returns 42
 * int val2 = ft_atoi("  -123"); // returns -123
 * int val3 = ft_atoi("+999abc"); // returns 999
 * int val4 = ft_atoi("invalid"); // returns 0
 * @endcode
 */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
