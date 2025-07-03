/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:26:21 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/03 14:39:26 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert a character to its digit value.
 * @param ch Character to convert.
 * @param base Target numeric base.
 * @return Digit value or -1 if invalid
 */
static int	get_digit(char ch, int base)
{
	int	digit;

	digit = 0;
	if (ch >= '0' && ch <= '9')
		digit = ch - '0';
	else if (ch >= 'a' && ch <= 'f')
		digit = ch - 'a' + 10;
	else if (ch >= 'A' && ch <= 'F')
		digit = ch - 'A' + 10;
	else
		return (-1);
	if (digit >= base)
		return (-1);
	return (digit);
}

/**
 * @brief Convert string to integer in specified base.
 * @param str String to convert.
 * @param base Numeric base (2-16).
 * @return Converted integer value.
 */
int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	sign;
	int	result;
	int	digit;

	i = 0;
	sign = 1;
	result = 0;
	if (base < 2 || base > 16 || !str)
		return (-1);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		digit = get_digit(str[i], base);
		if (digit < 0)
			break ;
		result = result * base + digit;
		i++;
	}
	return (result * sign);
}
