/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:13 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/16 00:19:06 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strrchr(const char *s, int c)
{
    const char *z;
    z = NULL;
    
    while (*s != '\0')
    {
        if (*s == c)
        {
            z = s;
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)s);
    }
    return ((char *)z);
}
