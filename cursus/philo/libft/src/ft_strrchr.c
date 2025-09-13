/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:17:47 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/29 01:53:23 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  description: look for a last char coincidence in a string
**  parameters: the string and a character in ascii
**  return: pointer to string if exits NULL if not
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len]);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
