/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:39 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/16 16:37:19 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t ft_strlcpy (char *dst, const char *src, size_t size)
{
    size_t i;
    size_t src_l;

    i = 0;
    src_l = 0;
    while (src[src_l] != '\0') // calculamos la longitud de source
    {
        src_l++;
    }
    if (size == 0) // si size es 0 devolvemos la longitud de source
    {
        return (src_l);
    }
    while (src[i] && i < size - 1)
    {
        dst[i] = src[i]; // copiamos en destino el source hasta el size - 1
        i++;
    }
    dst[i] = '\0'; // no aseguramos que el ultimo caracter es el null
    return (src_l);
}