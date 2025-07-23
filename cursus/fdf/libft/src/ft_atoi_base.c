/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:26:21 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/23 18:19:46 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_atoi_base.c
 * @brief Convert a character to its digit value in given base.
 * Determines numeric value of a character in the specified base,
 * handling both decimal digits and hexadecimal letters (both cases).
 * @note Case-insensitive for hexadecimal letters.
 * @param ch Character to convert (ASCII value).
 * @param base Target numeric base (2-16).
 * @return int Numeric value (0-15 if valid for the base),
 * -1 if character is invalid or exceeds base.
 * @warning Returns -1 if digit value exceeds specified base.
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
 * @file ft_atoi_base.c
 * @brief Determines the sign of a numeric string.
 * Check for and processes optional sign characters (+/-) at the specified
 * position in the string.
 * @note Preserves original sign if no valid sign character found.
 * @param str String to check (null-terminated).
 * @param sign Current sign value.
 * @param i Index position to check the sign.
 * @return int 1 for positive, -1 for negative, unchanged if no sign.
 */
int	ft_issign(const char *str, int sign, int i)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
			return (sign);
		}
	}
	return (sign);
}

/**
 * @file ft_atoi_base.c
 * @brief Converts a string to an integer in the specified base.
 * Parses the initial portion of a string and converts it to a 32-bit integer,
 * handling optional leading whitespace, an optional sign character (+/-),
 * and numerical digits in the specified base.
 * @note For base 16, accepts both uppercase and lowercase letters.
 * @note Stops conversion at first invaalid digit for the given base.
 * @note Does not detect integer overflow.
 * @param str Null-terminated string to convert.
 * @param base Numeric base for conversion (2-16).
 * @return int The converted integer value, or -1 if:
 * - Invalid base (not between 2-16).
 * - NULL input string.
 * - Invalid digit encountered for the given base.
 * @warning Returns -1 for any invalid input (base or string).
 * @code
 * // Example
 * int val1 = ft_atoi_base("1010", 2); // returns 10 (binary)
 * int val2 = ft_atoi_base("-FF", 16); // returns -255 (hex)
 * int val3 = ft_atoi_base("  +42", 10); // returns 42 (decimal)
 * int val4 = ft_atoi_base("invalid", 10); // returns -1 (error)
 * @endcode
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
	sign = ft_issign(str, sign, i);
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
