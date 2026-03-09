/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:36:59 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/17 02:34:42 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for 
 * the first instance of c.
 *
 * @param s A pointer to the memory area.
 * @param c The character to be searched.
 * @param n The number of bytes to be scanned.
 * @return A pointer to the matching byte or NULL if the character does not 
 * occur in the given memory area.
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*byte;
	unsigned char	character;
	size_t			i;

	byte = (unsigned char *) s;
	character = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (byte[i] == character)
			return ((void *)&byte[i]);
		i++;
	}
	return (NULL);
}
