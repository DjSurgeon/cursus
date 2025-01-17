/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:05:21 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 12:18:43 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_memset (void *s, int c, size_t n)
{
    char *a;    // al igual que en bzero el puntero void lo pasaremos a puntero de char
    unsigned char d;    // convertiremos el valor que nos den a un unsigned char el cual representa 1 byte (tamaño minimo de la memoria)
    size_t i;
    
    d = (unsigned char) c; //casteo
    a = (char *)s;       
    i = 0;
    
    while (i < n)
    {
        a[i] = d; // vamos a asignar desde el principio el valor deseado durante el tamaño i
        i++;
    }
    return (s); // devolvemos s que es lo que dice el manual
}
int main (void)
{
    char s[] = "Hello world!";
    int c = 32;
    size_t size = 4;

    ft_memset(s, c, size);
    
    return (0);
}