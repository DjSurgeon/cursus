/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:36:59 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 11:53:27 by serjimen         ###   ########.fr       */
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
	unsigned char	*string;
	unsigned char	character;
	size_t			i;

	string = (unsigned char *) s;
	character = (unsigned char) c;
	i = 0;
	while (string[i] != '\0')
		if (string[i] == n)
			return ((void *) string[i]);
	i++;
	return (NULL);
}
