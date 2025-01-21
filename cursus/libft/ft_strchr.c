/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:46:29 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/22 00:51:32 by sergio-jimene    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
        {
            return ((char *)s);
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)s);
    }
    return (NULL);
}
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c == '\0')
		return ((char *)s);
	while (s[i] != '\0')
	{
		if (s[i] = c)
			return ((char *)s[i]);
		i++;
	}
	return (NULL);
}
