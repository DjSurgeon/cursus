/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:43:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 13:10:50 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: locate the first ocurrence of the string little,
** in the big string
**	parameters: two string and the length to look for
**	return: if little is NULL return big, if little don't exit in
** big return NULL and if exits pointer to first character of little
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	big_len;
	size_t	little_len;

	i = 0;
	j = 0;
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (little[j] == '\0' || little == NULL)
		return ((char *)big);
	else if (len > big_len)
	{
		return (NULL);
	}
	while (big[i] != '\0')
	{
		if (ft_strncmp(&big[i], &little[j], little_len - 1) == 0)
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
