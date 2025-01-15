/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:12:03 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/13 23:58:05 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);
int ft_isascii(int c);
int ft_isalnum(int c);

void ft_putchar(char c)
{
    write (1, &c, 1);
}
int ft_isascii(int c)
{
    if  (c >= 0 && c <= 127)
    {
        return (1);
    }
    else 
    {
        return (0);
    }
}
int ft_isalnum(int c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    {
        return (1);
    }
    else 
    {
        return (0);
    }
}

int main (void)
{
    char c;

    c = 100;
    ft_putchar(ft_isalnum(c) + '0');
    return (0);
}