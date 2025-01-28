/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:46:29 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/28 15:10:06 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include "libft.h"

void ft_putstr(char *s);
void ft_putchar(char c);
char *ft_strchr(const char *s, int c);

void ft_putstr(char *s) // imprimir cadenas
{
    size_t i;
    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar(s[i]);
        i++;
    }    
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}

char *ft_strchr(const char *s, int c)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            return ((char *)&s[i]); // retornamos la coincidencia
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)&s[i]);
    }
    return (NULL); // si no hubiera coincidencia NULL
}
int main(void)
{
    const char s[] = "Holllo!";
    int c;
    c = 'o';

    ft_putstr(ft_strchr(s, c)); // Expect olllo!
    ft_putchar('\n');
    ft_putstr(ft_strchr(s, 'l')); // Expect lllo!   
    ft_putchar('\n');
    ft_putstr(ft_strchr(s, '\0')); // Expect '\0' 
    
    return (0);
}