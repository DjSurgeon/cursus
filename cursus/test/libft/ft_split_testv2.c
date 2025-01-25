/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_testv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:23:03 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/25 16:28:06 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int assign_malloc(char **array, size_t position, size_t size)
{
	size_t i;

	i = 0;
	array[position] = malloc(size); // Reservamos memoria para la posición 'position' del array.
	if (array[position] == NULL)	// Si `malloc` falla:
	{
		while (i < position) // Recorremos todas las posiciones ya reservadas:
		{
			free(array[i]); // Liberamos la memoria de cada una de ellas.
			i++;
		}
		free(array); // Liberamos el array completo.
		return (1);	 // Indicamos que hubo un fallo retornando 1.
	}
	return (0); // Retornamos 0 si la reserva fue exitosa.
}
/*
Esta función garantiza que se pueda asignar memoria para una posición específica en un array de cadenas. Si ocurre un error, limpia toda la memoria reservada previamente.
*/
int ft_substr_cpy(char **substrings_array, char const *string, char character)
{
	size_t i;		   // Iterador para recorrer la cadena.
	size_t j;		   // Índice para el array de substrings.
	size_t substrings; // Número total de substrings.
	size_t string_len; // Longitud de cada substring.

	i = 0;
	j = 0;
	substrings = 0;
	while (string[i] != '\0') // Recorremos toda la cadena:
	{
		string_len = 0;										// Inicializamos la longitud del substring.
		while (string[i] != '\0' && string[i] == character) // Ignoramos caracteres separadores.
		{
			i++;
		}
		while (string[i] != '\0' && string[i] != character) // Contamos caracteres no separadores.
		{
			string_len++;
			i++;
		}
		if (string_len != 0) // Si encontramos un substring:
		{
			if (assign_malloc(substrings_array, j, string_len + 1)) // Asignamos memoria para él.
			{
				return (1); // Si `assign_malloc` falla, retornamos 1.
			}
			ft_strlcpy(substrings_array[j], &string[i - string_len], string_len + 1); // Copiamos el substring en la posición adecuada.
			j++;																	  // Pasamos al siguiente substring.
		}
	}
	return (0); // Todo salió bien, retornamos 0.
}
/*
Divide la cadena original en substrings delimitados por el carácter character y los copia en el array substrings_array
*/
size_t ft_count_strings(const char *string, char character)
{
	size_t sub_strings; // Contador de substrings.
	size_t i;			// Iterador para recorrer la cadena.
	int is_in_string;	// Bandera para saber si estamos dentro de un substring.

	sub_strings = 0; // Inicializamos el contador.
	i = 0;
	while (string[i] != '\0') // Recorremos toda la cadena:
	{
		is_in_string = 0;									// Inicializamos como fuera de un substring.
		while (string[i] != '\0' && string[i] == character) // Ignoramos caracteres separadores.
		{
			i++;
		}
		while (string[i] != '\0' && string[i] != character) // Si entramos en un substring:
		{
			if (is_in_string == 0) // Solo contamos el inicio de un nuevo substring.
			{
				sub_strings++;	  // Incrementamos el contador.
				is_in_string = 1; // Indicamos que estamos dentro de un substring.
			}
			i++;
		}
	}
	return (sub_strings); // Retornamos el número total de substrings.
}
/*
Cuenta la cantidad de substrings en una cadena delimitada por el carácter character.
*/
char **ft_split(char const *s, char c)
{
	size_t substrings;		 // Número de substrings.
	char **substrings_array; // Array que contendrá los substrings.

	if (s == NULL)												  // Si la cadena de entrada es NULL:
		return (NULL);											  // Retornamos NULL.
	substrings = ft_count_strings(s, c);						  // Calculamos el número de substrings.
	substrings_array = malloc((substrings + 1) * sizeof(char *)); // Reservamos memoria para el array de substrings.
	if (substrings_array == NULL)								  // Si falla el malloc:
		return (NULL);
	substrings_array[substrings] = NULL;			// Asignamos NULL al final del array.
	if (ft_substr_cpy(substrings_array, s, c) == 1) // Si falla al copiar los substrings:
	{
		return (NULL); // Retornamos NULL.
	}
	return (substrings_array); // Retornamos el array con los substrings.
}
/*
Divide una cadena s en un array de substrings, delimitados por el carácter c
*/
