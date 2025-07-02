/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:12:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 17:36:44 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if a character is a hexadecimal digit.
 * Verifies if the character is a valid hexadecimal digit:
 * - Decimal digits (0-9)
 * - Uppercase hexadecimal letters (A-F)
 * - Lowercase hexadecimal letters (a-f)
 * @param c Character to check (ASCII value as integer)
 * @return 1 if hexadecimal digit, 0 otherwise.
 */

int	ft_isxdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}
