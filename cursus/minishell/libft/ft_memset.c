/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:09:13 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/22 13:44:55 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	value;

	value = (unsigned char) c;
	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = value;
		i++;
	}
	return (s);
}
