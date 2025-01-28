/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:43:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/28 11:25:27 by serjimen         ###   ########.fr       */
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

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (little[j] != '\0' && big[i] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i - (j - 1)]);
		}
		i++;
	}
	return (NULL);
}
