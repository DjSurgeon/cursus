/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:37 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/20 17:00:58 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strjoin(char const*s1, char const *s2)
{
    char *new_string; // nueva string, es la concatenación de s1 y s2
    size_t i; // variable para iterar en s1
    size_t j;   // variable para iterar en s2
    size_t size_s1; // variable para el tamaño de la s1
    size_t size_s2; // variable para el tamaño de la s2

    i = 0;    
    j = 0;
    size_s1 = ft_strlen(s1);
    size_s2 = ft_strlen(s2);
    new_string = malloc(size_s1 + size_s2 + 1); // reservo el espacio en memoria de la longitud de s1 y s2, mas el '\0'
    if (new_string == NULL)
    {
        return (NULL); // si no se puede asignar memoria retornamos NULL
    }
    
    while (i < size_s1) // iteramos por la s1 y copiamos su contenido en la nueva string
    {
        new_string[i] = s1[i];
        i++;
    }
    while (j < size_s2) // iteramos por la s2 y copiamos el contenido en la nueva string despues de s1
    {
        new_string[i+j] = s2[j];
        j++;
    }
    new_string[i+j] = '\0';    
    return (new_string);
}
