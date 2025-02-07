/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:47:37 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/07 19:08:03 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	static char		*buffer_dinamico = NULL;
	// char		buffer[10];
	int			BUFFER_SIZE = 5;
	int			fd;
	char		*file_name = "hello.txt";
	size_t		bytes_read;
	
	fd = open(file_name, O_RDONLY);
	printf("El file descriptor asignado es: %i\n", fd);
	if (buffer_dinamico == NULL)
	{
		buffer_dinamico = malloc(BUFFER_SIZE + 1);
		if (buffer_dinamico == NULL)
			return (printf("Error al asignar buffer dinamico."));
	}
	while ((bytes_read = read(fd, buffer_dinamico, BUFFER_SIZE)) > 0)
	{
		buffer_dinamico[bytes_read] = '\0';
		printf("Cantidad de bytes leidos: %zu\nEn un buffer de tamaño: %i\n", bytes_read, BUFFER_SIZE);
		printf("Los datos leidos son:\n%s\n", buffer_dinamico);
	}
	if (bytes_read == 0)
	{
		printf("%s", buffer_dinamico);
		free(buffer_dinamico);
		return (printf("EOF Alcanzado"));
	}
	
	close(fd);
	return (0);
}
