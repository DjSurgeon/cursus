/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:46:15 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/30 14:40:08 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: duplicate a string
**	parameters: the string to duplicate
**	return: the duplicate string
*/

#include "libft.h"

void	*ft_strdup(const char *s)
{
	char	*new_string;
	size_t	s_size;
	size_t	i;

	i = 0;
	s_size = ft_strlen(s);
	new_string = ft_calloc(1, s_size + 1);
	if (!new_string)
		return (NULL);
	while (i < s_size)
	{
		new_string[i] = s[i];
		i++;
	}
	return (new_string);
}
