/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:39:08 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/23 14:20:58 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isdigit.c
 * @brief Checks if a character is a decimal digit.
 * Determines whether the passed character represents a decimal digit (0-9)
 * in the ASCII character set.
 * @note Only validates standard ASCII digits (0-9).
 * @param c Character to check (ASCII value).
 * @return int 1 if the character is a digit, 0 otherwise.
 * @code
 * // Example
 * ft_isdigit('5'); // returns 1
 * ft_isdigit('a'); // returns 0
 * ft_isdigit(-1); // return 0
 * @endcode
 */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
