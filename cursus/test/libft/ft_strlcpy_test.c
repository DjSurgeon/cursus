/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:20:29 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/16 16:36:10 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}
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
int main(void)
{
    const char *src = "hello";
    char dst[5];
    size_t size = 3;
    ft_putchar(ft_strlcpy(dst, src, size) + '0'); // expect 5
    return (0);
}