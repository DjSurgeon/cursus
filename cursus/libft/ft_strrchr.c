/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:13 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 12:41:44 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  description: look for a last char coincidence in a string
**  parameters: the string and a character in ascii
**  return: pointer to string if exits NULL if not
*/

#include "libft.h"

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
