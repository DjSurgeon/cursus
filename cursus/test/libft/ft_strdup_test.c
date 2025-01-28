/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:54:46 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/28 10:32:19 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
void *ft_strdup (const char *s)
{
    char *new_string;   // puntero al nuevo string
    size_t s_size;      // variable para almacenar el tamaño de la string original
    size_t i;           // variable para iterar sobre la string

    i = 0;
    s_size = ft_strlen(s) + 1;          // calculamos el tamaño de la string + el carácter nulo
    new_string = malloc(s_size);        // reservamos la memoria del tamaño de la string
    if  (new_string == NULL)            // si malloc da algun fallo se devuelve NULL
        return (NULL);
    while (i < s_size - 1)                // empezamos a iterar hasta el tamaño solicitado
    {
        new_string[i] = s[i];           // copiamos la string en la nueva string
        i++;
    }
    new_string[i] = '\0';
    return (new_string);                // devolvemos el puntero a la nueva string
}
int main (void)
{
    char s[] = "Hello 42!!";
    char *d;
    
    d = ft_strdup(s);
    write(1, d, 11);
    free (d);
    
    return (0);
}