/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:20:27 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/22 13:45:05 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;

	ptr_src = (const unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	if (ptr_src == ptr_dest || n == 0)
		return (dest);
	if (ptr_src < ptr_dest)
	{
		ptr_src = ptr_src + n;
		ptr_dest = ptr_dest + n;
		while (n--)
			*--ptr_dest = *--ptr_src;
	}
	else
	{
		while (n--)
			*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}
