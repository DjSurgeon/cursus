/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:17:47 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 19:43:05 by serjimen         ###   ########.fr       */
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
	const char	*last_character;
	size_t		i;

	i = 0;
	last_character = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			last_character = s;
		}
		i++;
	}
	if (c == '\0')
		return ('\0');
	return ((char *)last_character);
}
