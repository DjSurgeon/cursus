/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:31:59 by serjimen          #+#    #+#             */
/*   Updated: 2026/03/13 10:47:05 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a string to an integer (ASCII to Int).
 *
 * Skips leading whitespace characters, handles an optional sign,
 * and converts subsequent digits into an integer value.
 *
 * @param str The string to convert.
 * @return The converted integer value.
 */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}
