/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:30:03 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/23 17:42:33 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isspace.c
 * @brief Check if a character is a whitespace character.
 * Determines whether the passed character is one of the standard whitespace
 * characters in ASCII:
 * - Space (' ', ASCII 32).
 * - Form feed ('\f').
 * - Newline ('\n').
 * - Carriage return ('\r').
 * - Horizontal tab ('\t').
 * - Vertical tab ('\v').
 * @note Only checks for standard ASCII whitespace characters.
 * @param c Character to check (ASCII value).
 * @return int 1 If the character is whitespace, 0 otherwise.
 * @code
 * // Example
 * ft_isspace(' '); // returns 1
 * ft_isspace('\t'); // returns 1
 * ft_isspace('a'); // returns 0
 * ft_isspace('1'); // returns 0
 * @endcode
 */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == 32 || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
