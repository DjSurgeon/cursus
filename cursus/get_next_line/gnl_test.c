/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:43:36 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/04 14:31:05 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	ssize_t read(int fd, void *buf, size_t count);
*	
*	La funcion read, lee count bytes desde el file descriptor fd y los almacena en el buffer *buf
*	El valor devuelto de read es la cantidad de bytes leidos. 
*	Puede ser menos de count si se llega al final del archivo o hay menos datos disponibles
*	Si devuelve 0 es que se ha llegado al EOF o final del archivo
*	Si devuelve -1 es que ha habido algun error
*/

/*
*	int open(const char *pathname, int flags, mode_t mode);
*
*	La función open se utiliza para abrir archivos y obtener el file descriptor
*	pathname es la ruta del archivo a abrir
*	flags es el modo de apertura del archivo, lectura, escritura...
*	mode (es una flas opcional), son los permisos del archivo si se crea (ejemplo 0644)
*	Si open tiene exito devuelve el int del file descriptor
*	Si hay un error devuelve -1 
*/

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		bytes_read;
	size_t	nbytes;
	int		file_descriptor;
	char	*buffer_read;
	nbytes = 3; // Vamos a leer de 3 en 3 los bytes del fd
	
	file_descriptor = open("example.txt", O_RDONLY); // abrimos el archivo example.txt

	// Control de errores del file descriptor ****************************************
	
	if (file_descriptor == -1)
	{
		printf("Error no se pudo abrir el File descriptor\n");
	}
	else
	{
		printf("File descriptor: %d\n", file_descriptor);
	}

	// Calloc del buffer, se inicializa con el tamaño del buffer +1 para el caracter '\0'
	
	buffer_read = ft_calloc(nbytes + 1, sizeof(char));
	if (buffer_read == NULL)
		return (NULL);
	
	// Get Next Line *******************************************************************

	bytes_read = read(file_descriptor, buffer_read, nbytes);
	int	i = 1;
	while (bytes_read >= 0)
	{
		if (bytes_read == 0)
		{
			printf("Has llegado al final del archivo o no hay nada que leer.\n");
			free(buffer_read);
			return (0);
		}
		if (bytes_read >= 0)
		{
			printf("[%i]Buffer leido: %s\n", i, buffer_read);
			buffer_read = ft_calloc(nbytes + 1, sizeof(char));
			if (buffer_read == NULL)
				return (NULL);
			printf("Número de bytes leidos: %i\n", (int)nbytes);
			i++;
		}	
		bytes_read = read(file_descriptor, buffer_read, nbytes);
	}
	return (0);
}