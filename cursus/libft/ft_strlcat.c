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

/**
 * @brief Appends string src to the end of dst. It will append at most 
 * size - strlen(dst) - 1 characters. It will then NUL-terminate, unless 
 * size is 0 or the original dst string was longer than size.
 *
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string they tried to create.
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
