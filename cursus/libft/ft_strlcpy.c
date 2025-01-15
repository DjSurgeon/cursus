/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:39 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 17:32:00 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t ft_strlen(const char *s);
size_t ft_strlcpy (char *dst, const char *src, size_t size);

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

size_t ft_strlcpy (char *dst, const char *src, size_t size)
{
    size_t src;
    size_t dst;

    
}