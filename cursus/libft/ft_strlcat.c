/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:38:04 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/16 17:16:09 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t ft_strlen(const char *s)
{
    size_t i;
    i = 0;
    while (*s != '\0')
    {
        s++;
        i++;
    }
    return (i);
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t src_l;
    size_t dst_l;

    i = 0;
    src_l = ft_strlen(src);
    dst_l = ft_strlen(dst);
    if (size == 0) // si size es 0 devolvemos la longitud de source
    {
        return (src_l);
    }
    while (dst[dst_l] && i < size - 1)
    {
        dst[dst_l + i] = src[i]; // copiamos la cadena source en destino
        i++;
    }
    dst[dst_l + i] = '\0'; // no aseguramos que el ultimo caracter es el null
    return (src_l);
}