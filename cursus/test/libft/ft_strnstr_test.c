/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:43:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 17:01:44 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);
void ft_putstr(char *s);
size_t ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr (const char *big, const char *little, size_t len);

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
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    i = 0;
    while (i <= n)
    {
        if (s1[i] == s2[i])
        {
            i++;
        }
        else if (s1[i] > s2[i])
        {
            return (1);
        }
        else if (s1[i] < s2[i])
        {
            return (-1);
        }
    }
    return (0);
}
char *ft_strnstr (const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;
    size_t big_len;
    size_t little_len;
    
    i = 0;
    j = 0;
    big_len = ft_strlen(big);
    little_len = ft_strlen(little);

    if (little[j] == '\0' || little == NULL)
    {
        return ((char *)big);
    }
    else if (len > big_len)
    {
        return (NULL);
    }
    while (big[i] !='\0')
    {
        if (ft_strncmp(&big[i], &little[j], little_len - 1) == 0)
        {
         return ((char *)&big[i]);
        }
        i++;
    }
    return (NULL);
}

int main (void)
{
    char big[] = "hola mundo!";
    char little[] = "la";
    size_t len = 6;

    ft_putstr((char*)ft_strnstr(big, little, len));

    return(0);
}