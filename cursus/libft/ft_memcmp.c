/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:43:43 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 11:59:03 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: compare memoria areas
**	parameters: 2 strings and n bytes
**	return:	0 if strings are equals, 1 or -1 if s1 > s2 or s1 < s2
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*memory1;
	unsigned char	*memory2;
	size_t			i;

	memory1 = (unsigned char *) s1;
	memory2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (memory1[i] < memory2[i])
			return (-1);
		if (memory1[i] > memory2[i])
			return (1);
		i++;
	}
	return (0);
}
