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

/*
**	description: move n bytes from source to destiny
**	parameters: source, destiny and n bytes to move
**	return: pointer to destiny
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
