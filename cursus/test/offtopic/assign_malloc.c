/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:12:15 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/29 16:13:26 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
