/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:43:43 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/22 00:14:45 by sergio-jimene    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
