/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:12:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/23 16:27:59 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_xdigit.c
 * @brief Check if a character is a hexadecimal digit.
 * Verifies if the character is a valid hexadecimal digit:
 * - Decimal digits (0-9)
 * - Uppercase hexadecimal letters (A-F)
 * - Lowercase hexadecimal letters (a-f)
 * @note Validates both uppercase and lowercase hex digits.
 * @param c Character to check (ASCII value as integer)
 * @return 1 if hexadecimal digit, 0 otherwise.
 * @code
 * // Example
 * ft_isxdigit('A'); // returns 1
 * ft_isxdigit('f'); // returns 1
 * ft_isxdigit('9'); // returns 1
 * ft_isxdigit('G'); // returns 0
 * ft_isxdigit('z'); // returns 0
 * @endcode
 */

#include "libft.h"

int	ft_isxdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}
