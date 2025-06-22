/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:56:12 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 12:11:42 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: put the character c in s for n bytes
**	parameters: character, destiny and number of bytes
**	return: pointer to destiny
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	character;
	size_t			i;

	string = (unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		string[i] = character;
		i++;
	}
	return ((void *)s);
}
