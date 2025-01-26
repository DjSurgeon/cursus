/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:03:34 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/26 11:36:36 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_bzero (void *s , size_t n)
{
    unsigned char *string; // trabajamos con unsigned char, para trabajar los 8 bytes de memoria, si trabajas con signo el primer byte corresponde al signo
    size_t i; // sirve para almacenar datos y cantidades de memoria. Es unsigned por lo tanto no tiene valores negativos útil para iterar
    
    string = (unsigned char *)s; // casteo de un puntero void a unsigned char
    i = 0;
    
    while (i < n)
    {
        string[i] = '\0';
        i++;
    }
}

int main(void){
    char s[] = "Hola Mundo!";
    size_t n = 5;
    ft_bzero(s, n);

    return (0);
}