/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:46:29 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 16:46:38 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *s);
void ft_putchar(char c);
char *ft_strchr(const char *s, int c);

void ft_putstr(char *s)
{
    size_t i;
    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar(s[i]);
        s++;
    }    
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
char *ft_strchr(const char *s, int c)
{
    size_t i;
        
    i = 0;
    
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            return ((char *)&s[i]); // devolvemos el puntero desde la posicion del caracter encontrado
        }
        s++;
    }
    return (NULL);
    
}
int main(void)
{
    const char s[] = "Hola!";
    int c;
    c = 'o';

    ft_putstr(ft_strchr(s, c)); // Expect ola!

    return (0);
}