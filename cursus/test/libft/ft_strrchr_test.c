/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:13 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/16 00:22:56 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);
void ft_putstr(char *s);
char *ft_strrchr(const char *s, int c);

void ft_putchar(char c)
{
    write(1, &c, 1);
}
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
char *ft_strrchr(const char *s, int c)
{
    const char *z; // const char por que le vas a dar el valor de *s que es const char
    z = NULL; //En el caso de no encontrar ninguna coincidencia devolvemos NULL
    
    while (*s != '\0')
    {
        if (*s == c)
        {
            z = s; // Cada coincidencia es sobreescrita y nos quedamos con la ultima
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)s);
    }
    return ((char *)z);
}
int main (void)
{
    char string[] = "Hola Mando";
    char c = 'a';
    char d = 'e';
    ft_putstr(ft_strrchr(string, c)); // Expect ando
    ft_putchar('\n');
    ft_putstr(ft_strrchr(string, d)); // Expect NULL
    return (0);
}