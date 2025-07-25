/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:49:10 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/02 17:00:37 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
// #include "libft.h"
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total_size;
	void			*memory_pointer;
	unsigned char	*clean_memory;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	memory_pointer = malloc(total_size);
	if (memory_pointer == NULL)
		return (NULL);
	clean_memory = (unsigned char *)memory_pointer;
	i = 0;
	while (i < total_size)
	{
		clean_memory[i] = 0;
		i++;
	}
	return (clean_memory);
}
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
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	source_len;
	size_t	i;

	source_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (source_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (source_len);
}
int	assign_malloc(char **array, size_t position, size_t size)
{
	size_t	i;
	
	i = 0;
	array[position] = malloc(size); // malloc en cada string del array

	if (array[position] == NULL) // si falla en alguna posicion
	{
		while (i <  position) // si falla en cualquier posicion
		{
			free(array[i]); // se liberan todas las posiciones
			i++;
		}
		free(array); // liberamos el array
		return (1); // retornamos fallo
	}
	//free(array);
	return (0); // ok
}
// funcion que va a copiar los substring en el array en la posicion correcta return 0 si es exitoso, return 1 si sale mal
int	ft_substr_cpy(char **substrings_array, char const *string, char character, size_t substrings)
{
	size_t	i; // iterador strings
	size_t	j; // iterador malloc
	size_t	string_len; // longitud de cada substring
	
	i = 0;
	j = 0;
	while (string[i] != '\0' && j < substrings) // utilizamos la lógica de la funcion anterior para movermos igual a traves de la string
	{
		string_len = 0;
		while (string[i] != '\0' && string[i] == character)
			i++;
		while (string[i] != '\0' && string[i] != character)
		{
			string_len++; // longitud de la string
			i++;
		}
		if (string_len != 0)
		{
			if (assign_malloc(substrings_array, j, string_len + 1)) // funcion para asignar la memoria de cada string dentro del array
				return (1);
		}
		ft_strlcpy(substrings_array[j], &string[i - string_len], string_len + 1);
		j++;
	}
	return (0); // todo ok!
}

size_t ft_count_strings(const char *string, char character)
{
	size_t sub_strings; // variable para el numero de sub strings
	size_t i;			// iterador
	int is_in_string;	// flag para saber si estoy dentro de una string

	sub_strings = 0; // inicializamos en 0
	i = 0;
	// is_in_string = 0 estoy fuera de la string, 1 estoy en dentro de la string
	while (string[i] != '\0')
	{
		is_in_string = 0; // fuera de la string
		while (string[i] != '\0' && string[i] == character)
		{
			i++;
		}
		while (string[i] != '\0' && string[i] != character)
		{
			if (is_in_string == 0)
			{
				sub_strings++;
				is_in_string = 1; // dentro de la string
			}
			i++;
		}
	}
	return (sub_strings); // retornamos el numero de sub strings que tenemos
}

char **ft_split(char const *s, char c)
{
	// 1. contar la cantidad de palabra en la string
	size_t 	substrings; // numero de substrings
	char	**substrings_array;

	if (!s) // si no existe la string, retornamos null
		return (NULL);
	substrings = ft_count_strings(s, c); // funcion auxiliar para saber cuantas subtrings vamos a tener
	substrings_array = ft_calloc(substrings, sizeof(char *)); // malloc((substrings + 1) * sizeof(char *)); // malloc de cada substring encontrada + 1 ya que la ultima sera null ft_calloc(substrings, sizeof(char));
	if (substrings_array == NULL)
		return (NULL);
	// substrings_array[substrings] = NULL; // el ultimo array sera NULL para saber que se ha acabado el array
	// 2. Funcion para copiar los strings, en las posiciones correctas del array.
	if (ft_substr_cpy(substrings_array, s, c, substrings) == 1) /********añado el parametro subtrings*/
	{
		return (NULL);
	}
	return (substrings_array);
}

int main(void)
{
	// char *s1 = " hola   que tal    vaaassss    lololo    lolaloe dfasd  455677!   3·$·\"  $                ";
	// char *s2 = "";
	char **v = ft_split("holaque", ',');
	// char **v = ft_split(s1, 'x');
	int i = 0;
	while(v[i])
		printf("%s\n", v[i++]); // Imprimimos cada substring
	i = 0;
	while (v[i])
		free (v[i++]);
	free(v); // Liberamos el array principal
	return (0);
}
