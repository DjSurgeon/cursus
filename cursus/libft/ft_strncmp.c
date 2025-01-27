/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:47:41 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 20:29:54 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: compare two strings for n size
**	parameters: the two strings and the size
**	result: 0 if the strings are equal, -1 and 1 if s2 < s1 and s2 > s1
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*byte1;
	unsigned char	*byte2;
	size_t			i;

	byte1 = (unsigned char *) s1;
	byte2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (byte1[i] != '\0' || byte2[i] != '\0'))
	{
		if (byte1[i] != byte2[i])
			return (byte1[i] - byte2[i]);
		i++;
	}
	return (0);
}
