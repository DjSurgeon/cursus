/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:57:07 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/29 10:44:09 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Erases the data in the n bytes of the memory starting at the location 
 * pointed to by s.
 *
 * @param s A pointer to the memory area to be zeroed.
 * @param n The number of bytes to be zeroed.
 */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;
	size_t			i;

	string = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}
