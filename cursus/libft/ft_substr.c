/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:05:00 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 15:25:57 by serjimen         ###   ########.fr       */
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
	new_substring = malloc(len + 1);
	if (new_substring == NULL || s == NULL)
	{
		return (NULL);
	}
	if (start > ft_strlen(s) || len == 0)
	{
		return ("");
	}
	while (i < len)
	{
		new_substring[i] = s[start];
		i++;
		start++;
	}
	new_substring[i] = '\0';
	return (new_substring);
}
