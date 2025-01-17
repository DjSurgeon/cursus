/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:16:28 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 10:50:16 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}
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
    size_t i;   // indice para recorrer y escribir src
    size_t src_l;   // longitud de src
    size_t dst_l;   // longitud de dst

    i = 0;
    src_l = ft_strlen(src);
    dst_l = ft_strlen(dst);
    if (size <= dst_l)
    {
        return (size + src_l);  // si size es menor del tamaño de donde intentamos copiar, devolveremos la longitud de src + size, por ejemplo en el caso de 0, devolveremos la longitud de src.
    }
    while (src[i] && (dst_l + i < size - 1)) // este while nos indica que la posicion donde vamos a empezar a concatenar, esta dentro del tamaño permitido -1 para poder incluir el null al final.
    {
        dst[dst_l + i] = src[i]; // copiamos la cadena source en destino
        i++;
    }
    dst[dst_l + i] = '\0'; // nos aseguramos que el ultimo caracter es el null
    return (src_l + dst_l); // el valor de retorno es la suma total de la longitud de las cadenas.
}
int main(void)
{
    char dst[25] = "Hi ";
    const char *src = "42!";
    size_t size = 6;

   ft_putchar(ft_strlcat(dst, src, size) + '0'); // expect 6

    return (0);
}