/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:37 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/28 15:33:19 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: concat a string with other string
**	paramaters: two string string source an string destiny
**	return: the concatenation of the strings
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	j = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new_string = ft_calloc(1, size_s1 + size_s2 + 1);
	if (!new_string)
		return (NULL);
	while (i < size_s1)
	{
		new_string[i] = s1[i];
		i++;
	}
	while (j < size_s2)
	{
		new_string[i + j] = s2 [j];
		j++;
	}
	return (new_string);
}
