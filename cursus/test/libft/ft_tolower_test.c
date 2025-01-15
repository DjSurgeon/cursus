/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:15:21 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 23:19:40 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_tolower(int c);
int ft_toupper(int c);
void ft_putchar(char c);

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_tolower(int c)
{

    if ( c >= 'A' && c <= 'Z')
    {
        c += 32;
        return (c);
    }
    return c;
}
int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        c -= 32;
        return (c);
    }
    return (c);
}

int main (void)
{
    char c;

    c = '2';

    ft_putchar(ft_tolower('A')); // Expect 'a'
    ft_putchar('\n');
    ft_putchar(ft_toupper('x')); // Expect 'z'
    ft_putchar('\n');
    ft_putchar(ft_tolower(c)); // Expect '2'
    return (0);
}