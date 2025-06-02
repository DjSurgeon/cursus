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

/*
**	description: look for a character in a string for n bytes
**	parameters: the string, the character in ascii and the number of bytes
**	return: pointer to coincidence byte if find it NULL if not
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
