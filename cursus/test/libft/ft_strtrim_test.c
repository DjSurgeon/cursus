/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:24:51 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/30 15:42:42 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
// #include "libft.h"

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
static  char *verify_len(size_t start, size_t end, char *new_string)
{
    new_string = malloc(1);
    if (!new_string)
        return (NULL);
    new_string[0] = '\0';
    return (new_string);
}
}
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
    if (start > end)
    {
        verify_len(start, end, new_string);
    }
    /*
    if (start > end)
        {
            new_string = malloc(1);
            if (!new_string)
                return (NULL);
            new_string[0] = '\0';
            return (new_string);
        }
    */
    new_string_len = end - start;
    new_string = (char *)malloc(new_string_len + 1);
    if (!new_string)
        return (NULL);
    ft_copy_string(new_string, s1, start, new_string_len);
    return (new_string);
}
int main(void)
{
    char const s1[] = "xxHI42xxxxx";
    char const set[] = "x";
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