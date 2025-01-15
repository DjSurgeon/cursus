/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:15:21 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/13 22:51:35 by serjimen         ###   ########.fr       */
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

    if ( c >= 65 && c <= 90)
    {
        c += 32;
        return c;
    }
    else
    {
        return c;
    }
}
int ft_toupper(int c)
{
    if (c >= 97 && c <= 122)
    {
        c -= 32;
        return c;
    }
    else 
    {
        return c;
    }
}

int main (void)
{
    char c;

    c = '2';

    ft_putchar(ft_tolower(c));
    ft_putchar('\n');
    ft_putchar(ft_toupper(c));
    ft_putchar('\n');
    return (0);
}