/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:44 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/21 21:48:37 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *new_substring;   // puntero a la substring de s
    size_t i;              // variable para iterar

    i = 0;
    new_substring = malloc(len + 1); // guardamos la memoria de la substring mas el caracter nulo
    if (new_substring == NULL || s == NULL) 
    {
        return (NULL); // Si tenemos algun error al reservar la memoria devolvemos NULL, o si la entrada de la string a copiar es NULL tambien tendremos la misma respuesta
    }
    if (start > ft_strlen(s) || len == 0) 
    {
        return (""); // si la longitud es 0, devolveremos una cadena vacia o si queremos copiar en un punto mas alla de la longitud de la cadena original
    }
    while (i < len) 
    {
        new_substring[i] = s[start]; // copiamos desde el indice start durante len y dejamos el ultimo para el caracter '\0'
        i++;
        start++;
    }
    new_substring[i] = '\0';
    return (new_substring);
}