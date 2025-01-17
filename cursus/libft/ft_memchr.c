/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:36:59 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 15:16:48 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_memchr (const void *s, int c, size_t n)
{
    unsigned char *string;
    unsigned char character;
    size_t i;

    string = (unsigned char *) s;
    character = (unsigned char) c;   
    i = 0;

    while (string != '\0')
    {
        if (i < n)
        {
            return ((void *) string[i]);
        }
        i++;
    }
    return (NULL);
}