/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:13 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/24 14:46:56 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *ft_strrchr(const char *s, int c)
{
    const char  *last_character;
    
    last_character = NULL;
    while (*s != '\0')
    {
        if (*s == c)
        {
            last_character = s;
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)s);
    }
    return ((char *)last_character);
}
