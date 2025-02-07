/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:39:02 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/06 10:43:48 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*
**	vamos a leer la entrada estandar del teclado
**	en read utilizamos el fd 0 la cual es la entrada estandar del teclado
**	esa entrada se almacenara en buffer
**	le vamos a indicar cuantos bytes va a leer
*/

int main(void)
{
	char 	buffer[42];
	int		is_read;
	size_t	bytes_to_read = 42;
	
	is_read = read(0, buffer, bytes_to_read); // leemos 42 bytes y los almacenamos en buffer

	if (is_read == -1)				// manejo de errores
	{
		printf("Error");
		return (-1);
	}
	else
	{
		printf("Read() ha leido %i bytes\n", is_read);
		printf("%s", buffer);
	}
	return (0);
}