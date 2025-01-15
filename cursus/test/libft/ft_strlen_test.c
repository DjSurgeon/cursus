/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:29:50 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 23:14:26 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);
size_t ft_strlen(const char *s);

void ft_putchar(char c)
{
    write(1, &c, 1);
}

size_t ft_strlen(const char *s)
{
    size_t i;
    i = 0; // Establecemos el contador en 0
    while (*s != '\0') // Recorremos la cadena y sumamos al contador
    {
        s++;
        i++;
    }
    return (i);
}
int main (void)
{
    char s1[] = "Hola! ";
    char s2[] = "42 Madrid";
    ft_putchar(ft_strlen(s1) + '0'); // Expect 6
    ft_putchar('\n');
    ft_putchar(ft_strlen(s2) + '0'); // Expect 9

    return (0);
}