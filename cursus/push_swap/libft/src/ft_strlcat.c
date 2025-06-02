/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:38:04 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 12:59:48 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: concatenate strings for a determinate size
**	parameters: two strings and size
**	return: the length of the concatenation
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destination_len;
	size_t	source_len;
	size_t	i;

	destination_len = ft_strlen(dst);
	source_len = ft_strlen(src);
	i = 0;
	if (size <= destination_len)
		return (size + source_len);
	while (src[i] && (destination_len + i < size - 1))
	{
		dst[destination_len + i] = src[i];
		i++;
	}
	dst[destination_len + i] = '\0';
	return (source_len + destination_len);
}
