/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:43:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/23 12:58:18 by sergio-jimene    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr (const char *big, const char *little, size_t len)
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
	{
		return ((char *)big);
	}
	else if (len > big_len)
	{
		return (NULL);
	}
	while (big[i] !='\0')
	{
		if (ft_strncmp(&big[i], &little[j], little_len - 1) == 0)
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
