/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:13 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 16:47:58 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t ft_strlen(const char *s);
char *ft_strrchr(const char *s, int c);

size_t ft_strlen(const char *s)
{
    size_t i;
    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strrchr(const char *s, int c)
{
    size_t i;

    i = ft_strlen(s);
    while (i >= 0)
    {
        if (s[i] == (char)c)
        {
            return ((char *)&s[i]);
        }
        i--;
    }
    return (NULL);
}