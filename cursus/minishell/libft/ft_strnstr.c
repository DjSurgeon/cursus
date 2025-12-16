/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:22:00 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/22 13:43:09 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s2 == 0)
		return ((char *) s1);
	i = 0;
	while ((s1[i]) && (i < n))
	{
		j = 0;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && (i + j) < n)
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char *) &s1[i]);
		i++;
	}
	return (NULL);
}
