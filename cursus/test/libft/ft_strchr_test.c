/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:46:29 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/14 14:04:27 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);
const char *ft_strchr(const char *s, int c);
void ft_str(char *s);

void ft_str(char *s)
{
    while (*s != '\0')
    {
        ft_putchar(*s);
        s++;
    }    
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
const char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        s++;
        if (*s == c)
        {
            return (s);
        }
        else
        {
            return (NULL);
        }

    }
    
}
int main(void)
{
    const char s[] = "Hola!";
    int c;
    c = 'o';

    ft_str(ft_strchr(s, c));

    return (0);
}