/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:03:34 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 14:50:42 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
void ft_bzero (void *s , size_t n)
{
    char *c;
    size_t i;
    c = (char *)s;  //casteamos el puntero void a puntero char para poder trabajar con el, por que? por que el puntero más basico y puedes apuntar a cualquier direccion de memoria, asegurandote que la dejas en cero byte a byte.
    i = 0;
    
    while (i < n)
    {
        c[i] = '\0';    // recorremos el tamaño n, inicializando en 0
        i++;
    }
}
*/

void ft_bzero (void *s , size_t n)
{
    unsigned char *string;
    size_t i;
    string = (unsigned char *)s;
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