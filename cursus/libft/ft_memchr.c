/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:36:59 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 12:43:10 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *memchr (const void *s, int c, size_t n)
{
    unsigned char d;
    unsigned char a;
    size_t i;

    d = (unsigned char) s;
    a = (unsigned char) c;   
    i = 0;

    while (d != '\0')
    {
        if (d == a)
        {
            return (d);
        }
        i++;
    }
    return (NULL);
}