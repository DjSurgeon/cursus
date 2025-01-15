/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:46:29 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 16:44:14 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strchr(const char *s, int c);

char *ft_strchr(const char *s, int c)
{
    size_t i;
        
    i = 0;
    
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            return ((char *)&s[i]);
        }
        s++;
    }
    return (NULL);
}