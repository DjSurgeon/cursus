/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:48:45 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/20 12:00:27 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *destination; // Puntero para representar la dirección del destino
    unsigned char *source;      // Puntero para representar la dirección del origen
    size_t i;                   // Variable auxiliar para el bucle

    // Casting de los punteros genéricos `void *` a `unsigned char *`
    destination = (unsigned char *)dest;
    source = (unsigned char *)src;
    i = 0; // Inicializamos el índice a 0 para el bucle

    // Caso 1: Si `dest` y `src` apuntan a la misma dirección o no hay nada que copiar (`n == 0`)
    if (destination == source || n == 0)
    {
        return ((void *)destination); // No hacemos nada, devolvemos el puntero `dest`
    }

    // Caso 2: Si `dest` está antes que `src` en memoria (no hay solapamiento hacia atrás)
    else if (destination < source)
    {
        while (i < n) // Copiamos de adelante hacia atrás
        {
            destination[i] = source[i]; // Copiamos cada byte de `src` a `dest`
            i++;
        }
    }
    // Caso 3: Si `dest` está después de `src` en memoria (posible solapamiento hacia atrás)
    else
    {
        i = n; // Iniciamos `i` al tamaño `n`
        while (i > 0) // Copiamos de atrás hacia adelante
        {
            destination[i - 1] = source[i - 1]; // Copiamos desde el último byte hacia el primero
            i--;
        }
    }

    // Devolvemos el puntero `dest` como indica el estándar de la función `memmove`
    return ((void *)destination);
}
int main (void)
{
    char src1[] = "abcdef";
    char dest1[] = "------";
    size_t size = 0;
    size_t size1 = 3;

    ft_memmove (dest1, src1, size);     // expect "------"
    ft_memmove (dest1, src1, size1);    // expect "abc---"
    ft_memmove (dest1, src1 + 3, 2);    // expect "de----"
    ft_memmove (dest1 + 2, src1, 2);    // expect "--ab--"
    
}