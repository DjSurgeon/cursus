/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:05:00 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/28 12:38:48 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: create a subtring from start of size len
**	parameters: initial string, the start position and the length
**	return: the new substring
*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_substring;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	new_substring = ft_calloc(1, len + 1);
	if (new_substring == NULL)
		return (NULL);
	while (i < len)
	{
		new_substring[i] = s[start];
		i++;
		start++;
	}
	new_substring[i] = '\0';
	return (new_substring);
}
