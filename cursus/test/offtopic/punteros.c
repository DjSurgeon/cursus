/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   punteros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:17:12 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 12:15:33 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Explicación de punteros

void ft_putchar(char c);
int incrementar (int a);
int doblar (int* b);

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int incrementar (int a)
{
    a++;
    return (a);
}
int doblar (int* b)
{
    *b = *b * 2;
    return (*b);
}
int main (void)
{
    int a;
    int b;
    int* c;
    int result;

    a = 0;
    b = 2;
    c = &b; // asignamos el valor al puntero

    ft_putchar(incrementar(a) + '0'); //expect 1
    ft_putchar('\n');
    ft_putchar(a + '0'); // expect 0
    // No se modifica el valor de la variable
    ft_putchar('\n');
    ft_putchar(*c + '0'); // expect 2
    ft_putchar('\n');
    result = doblar(c);
    ft_putchar(result + '0'); //expect 4
    ft_putchar('\n');
    ft_putchar(*c + '0'); // expect 4

    return (0);
}