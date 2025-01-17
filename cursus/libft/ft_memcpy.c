/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:20:01 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 15:33:47 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_memcpy (void *dest , const void *src, size_t n)
{
    unsigned char *destination;
    unsigned char *source;
    size_t i;

    destination = (unsigned char *)dest;
    source = (unsigned char *)src;
    i = 0;
    
    while (i < n)
    {
        destination[i] = source[i];
        i++;
    }
    return ((void *) destination);
}