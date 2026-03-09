/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:43:43 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/04 01:06:18 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 *
 * @param s1 A pointer to the first memory area.
 * @param s2 A pointer to the second memory area.
 * @param n The number of bytes to be compared.
 * @return An integer less than, equal to, or greater than zero if the first n 
 * bytes of s1 is found, respectively, to be less than, to match, or be 
 * greater than the first n bytes of s2.
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
		if (memory1[i] != memory2[i])
			return (memory1[i] - memory2[i]);
		i++;
	}
	return (0);
}
