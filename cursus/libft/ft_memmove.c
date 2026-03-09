/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:28:52 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/30 14:36:58 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Copies n bytes from memory area src to memory area dest. 
 * The memory areas may overlap.
 *
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to be copied.
 * @return A pointer to dest.
 */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	i = 0;
	if (destination == source || n == 0)
		return ((void *) destination);
	if (destination < source)
		ft_memcpy(dest, src, n);
	if (destination > source)
	{
		i = n;
		while (i > 0)
		{
			destination [i - 1] = source[i - 1];
			i--;
		}
	}
	return ((void *) destination);
}
