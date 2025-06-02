/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:20:01 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/17 13:49:40 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: copy n portion of memory from source to destination
**	parameters: source an destiny and number of bytes
**	return: pointer to destiny
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return ((void *) destination);
}
