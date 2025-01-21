/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:07:08 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/21 21:47:26 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strtrim (const char *s1, const char *set)
{
    char *new_string; // nueva string resultante despues de recortar los caracteres
    size_t i;
    
    i = 0;
    new_string = s1;
    while (new_string != '\0')
    {
        if (new_string[i] == set[i])
        {
         new_string[i] = '\0';
        }
        i++;
    }
    return (new_string);
}