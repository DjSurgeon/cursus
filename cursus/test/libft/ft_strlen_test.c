/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:29:50 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/14 14:37:12 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
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
    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}
int main (void)
{
    char s[] = "Hola!";

    ft_putchar(ft_strlen(s) + '0');

    return (0);
}