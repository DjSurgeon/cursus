/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:37:30 by serjimen          #+#    #+#             */
/*   Updated: 2026/03/09 11:15:00 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Writes a character to the standard output and counts it.
 *
 * @param c The character to be written.
 * @return The number of characters written (always 1 if successful).
 */

#include "libft.h"

int	ft_countchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}
