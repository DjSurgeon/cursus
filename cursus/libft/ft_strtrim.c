/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:07:08 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/25 17:06:22 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim (const char *s1, const char *set)
{
    char    *new_string;
    size_t  start;
    size_t  end;
    int     new_string_len;
    size_t  i;
    
    start = 0;    
    if (s1 == NULL || set == NULL)
        return (NULL);
    while (s1[start] != '\0' && ft_char_in_set(s1[start], set) == 1)
    {
        start++;
    }
    end = ft_strlen(s1);
    while (end > 0 && ft_char_in_set(s1[end - 1], set) == 1)
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