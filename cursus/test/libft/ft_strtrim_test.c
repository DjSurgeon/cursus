/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:24:51 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 14:53:35 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

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
/*
static int  ft_char_in_set(char c, const char *set)
{
    size_t  i;

    i = 0;
    while (set[i] != '\0')
    {
        if (set[i] == c)
        {
            return (1); // el caracter esta en set
        }
        i++;
    }
    return (0); // no esta el caracter
}

char *ft_strtrim (const char *s1, const char *set)
{
    char    *new_string;
    size_t  start;
    size_t  end;
    int     new_string_len;
    size_t  i;

    start = 0;
    if (s1 == NULL || set == NULL) // si alguno de los valores es null, devuelve null
        return (NULL);
    while (s1[start] != '\0' && ft_char_in_set(s1[start], set) == 1) // verificamos los valores si estan en set
    {
        start++;
    }
    end = ft_strlen(s1);
    while (end > 0 && ft_char_in_set(s1[end - 1], set) == 1) // verificamos a cadena desde el final
    {
        end--;
    }
    new_string_len = end - start;
    new_string = (char *)malloc(new_string_len + 1);
    if (!new_string)
        return (NULL);
    i = 0;
    while (i < new_string_len)
    {
        new_string[i] = s1[start + i];
        i++;
    }
    new_string[i] = '\0';
    return (new_string);
}
*/
static void ft_copy_string(char *dest, const char *src, size_t start, size_t len)
{
    size_t i;

    i = 0;
    while (i < len)
    {
        dest[i] = src[start + i];
        i++;
    }
    dest[i] = '\0';
}

static int ft_char_in_set(char c, const char *set)
{
    size_t i;

    i = 0;
    while (set[i] != '\0')
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char *ft_strtrim(const char *s1, const char *set)
{
    char *new_string;
    size_t start;
    size_t end;
    int new_string_len;

    start = 0;
    if (s1 == NULL || set == NULL)
        return (NULL);
    while (s1[start] != '\0' && ft_char_in_set(s1[start], set) == 1)
        start++;
    end = ft_strlen(s1);
    while (end > 0 && ft_char_in_set(s1[end - 1], set) == 1)
        end--;
    new_string_len = end - start;
    new_string = (char *)malloc(new_string_len + 1);
    if (!new_string)
        return (NULL);
    ft_copy_string(new_string, s1, start, new_string_len);
    return (new_string);
}
int main(void)
{
    char const s1[] = "abcDD6abc";
    char const set[] = "abc";
    char *result;

    result = ft_strtrim(s1, set);
    if (result)
    {
        write(1, result, ft_strlen(result));
        write(1, "\n", 1);
        free(result);
    }
    return (0);
}