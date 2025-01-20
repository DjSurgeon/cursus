/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:27:55 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/20 17:04:54 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *s)
{
    size_t i;
    i = 0;
    while (*s != '\0')
    {
        s++;
        i++;
    }
    return (i);
}

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
    /*
    if (s1 == NULL) 
    {
        s1 = ""; // Si la primera cadena es null se tratara como cadena vacia
    }
    if (s2 == NULL)
    {
        s2 = ""; // Si la segunda cadena es null se tratara como cadena vacia
    }
    */
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

int main (void)
{
    char s1[] = "Hello ";
    char s2[] = "";
    char *result;
    
    result = ft_strjoin(s1, s2);
    
    write(1, result, 7);
    free(result);
    return (0);
}