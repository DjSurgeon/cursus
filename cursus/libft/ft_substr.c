/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:44 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/25 16:59:22 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *new_substring;
    size_t i;
    
    i = 0;
    new_substring = malloc(len + 1);
    if (new_substring == NULL || s == NULL) 
    {
        return (NULL);
    }
    if (start > ft_strlen(s) || len == 0) 
    {
        return ("");
    }
    while (i < len) 
    {
        new_substring[i] = s[start];
        i++;
        start++;
    }
    new_substring[i] = '\0';
    return (new_substring);
}