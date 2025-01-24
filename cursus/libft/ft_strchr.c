/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:46:29 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/24 14:35:06 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
        {
            return ((char *)s); // retornamos la coincidencia
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)s);
    }
    return (NULL); // si no hubiera coincidencia NULL
}
