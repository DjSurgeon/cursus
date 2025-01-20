/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:39:07 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/20 14:43:32 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_calloc(size_t nmemb, size_t size)
{
    size_t i;                    // variable para iterar sobre los bloques de memoria
    size_t total_size;           // variable para almacenar el tamaño del numero de elementos por su tamaño
    void *memory_pointer;        // puntero para almacenar el bloque de memoria
    unsigned char *clean_memory; // puntero char para almacenar cada byte a 0

    if (nmemb == 0 || size == 0) // si algun parámetro es 0, se retorna el valor de malloc(0), el cúal siempre devuelve un puntero válido el cual se podra siempre liberar con free()
    {
        return (malloc(0));
    }
    i = 0;
    total_size = nmemb * size;           // calculamos la cantidad de memoria que necesitamos
    memory_pointer = malloc(total_size); // obtenemos el bloque de memoria con el tamaño deseado
    if (memory_pointer == NULL)          // si no podemos obtener el bloque de memoria => NULL
    {
        return NULL;
    }
    clean_memory = (unsigned char *)memory_pointer; // ese tamaño de memoria lo inicializamos a char para poder trbajar byte a byte
    while (i < total_size) // iteramos durante todos los bytes
    {
        clean_memory[i] = 0; // se inicizalizan en 0 todos los bytes
        i++;
    }
    return (void *)clean_memory; // retornamos el puntero a los bloques de memoria inicializados en 0
}