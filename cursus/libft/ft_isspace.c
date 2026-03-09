/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:31:59 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/09 10:31:59 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks for white-space characters.
 *
 * In the "C" and "POSIX" locales, these are: space, form-feed ('\f'),
 * newline ('\n'), carriage return ('\r'), horizontal tab ('\t'),
 * and vertical tab ('\v').
 *
 * @param c The character to check.
 * @return 1 if it is a whitespace character, 0 otherwise.
 */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
