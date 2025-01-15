/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:13 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 16:46:27 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);
void ft_putstr(char *s);
size_t ft_strlen(const char *s);
char *ft_strrchr(const char *s, int c);

void ft_putchar(char c)
{
    write(1, &c, 1);
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

char *ft_strrchr(const char *s, int c)
{
    size_t i;

    i = ft_strlen(s);
    while (i >= 0)
    {
        if (s[i] == (char)c)
        {
            return ((char *)&s[i]); //Devuelve el puntero desde la posición del carácter
        }
        i--;
    }
    return (NULL);
}
int main (void)
{
    char string[] = "Hola Mando";
    char c = 'a';
    ft_putstr(ft_strrchr(string, c)); // Expect ando
    return (0);
}