/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:13 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/14 16:26:22 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

size_t ft_strlen(const char *s);
const char *ft_strrchr(const char *s, int c);
void ft_putstr(char *s);
void ft_putchar(char c);

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
const char *ft_strrchr(const char *s, int c)
{
    size_t size;

    size = ft_strlen(s);
    while (size >= 0)
    {
        if (s[size] == c)
        {
            return (s);
        }
        size--;
    }
}
void ft_putstr(char *s)
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
int main (void)
{
    char string[] = "Hola Mando";
    char c = 'a';
    ft_putchar(ft_strrchr(string, c));
    //ft_putstr(ft_strrchr(string, c));
    return (0);
}