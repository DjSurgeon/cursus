/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:20:00 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 15:21:05 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  description: look for a first char coincidence in a string
**  parameters: the string and a character in ascii
**  return: pointer to string if exits NULL if not
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
