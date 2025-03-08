/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:33:36 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/03/07 15:35:09 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer)
{
	/*	Lectura del archivo
	Reservar memoria para la linea leida, hacemos un malloc, para guardar cada vez que ejecutamos read
	del tamaño + 1 para finalizar la cadena
	Leemos el archivo en partes del tamaño dado (BUFFER_SIZE), hasta encontrar un salto de linea
	*/
	
	char	*read_line;
	char	*temporal;
	char	*line;
	int		bytes_read;
	
	read_line = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!read_line)
		return (NULL);
	read_line[BUFFER_SIZE] = '\0';
	if (buffer == NULL)
		buffer = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_line, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, read_line);
		if ((temporal = ft_strchr(buffer, '\n')))
		{
			line = ft_substr(buffer, 0, ft_strlen(buffer) - ft_strlen(temporal) + 1);
			temporal = ft_strdup(temporal);
			free(buffer);
			buffer = temporal;
			free(read_line);
			return (line);
		}
	}
	free(read_line);
	if (buffer && *buffer != '\0')
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
		return (line);
	}
	line = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	/*	Control de errores
	Checkear el fd, los valores de la tabla de fd son siempre positivos
	Checkear el BUFFER_SIZE, el tamaño del buffer siempre tiene que se mayor que 0
	para poder escribir en el algo
	Checkear los permisos, read puede devolver 0 si mandas leer un archivo y tienes permisos
	si no tuviera permisos devolveria -1 y asi se controla el error
	*/
	static char	*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	return (buffer);
}

int main(void)
{
	int		file_descriptor;
	char	*gnl;

	file_descriptor = open("hello.txt", O_RDONLY);

	if (file_descriptor < 0)
	{
		printf("Error");
		return (1);
	}
	while ((gnl = get_next_line(file_descriptor)) != NULL)
	{
		printf("%s", gnl);
		free (gnl);
	}
	close(file_descriptor);
	return (0);
}