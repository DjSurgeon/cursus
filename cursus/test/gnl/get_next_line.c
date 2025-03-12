/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:33:36 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/03/12 00:05:58 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*extract_lines(int fd, char *read_line, char *buffer)
{
	int		bytes_read;
	char	*temporal;
	char	*line;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_line, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(read_line);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		read_line[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, read_line);
		if ((temporal = ft_strchr(buffer, '\n')))
		{
			line = ft_substr(buffer, 0, ft_strlen(buffer) - ft_strlen(temporal) + 1);
			temporal= ft_strdup(temporal + 1);
			free(read_line);
			free(buffer);
			buffer = temporal;
			return (line);
		}
	}
	return(NULL);
} */
/*	Lectura del archivo
Reservar memoria para la linea leida, hacemos un malloc, para guardar cada vez que ejecutamos read
del tamaño + 1 para finalizar la cadena
Leemos el archivo en partes del tamaño dado (BUFFER_SIZE), hasta encontrar un salto de linea
*/

char *read_line(int fd, char **buffer)
{

	char *read_line; // buffer temporal para leer el archivo
	char *temporal;	 // puntero temporal ara el rest despues de \n
	char *line;		 // linea a devolver
	int bytes_read;	 // numero de bytes leidos por read

	read_line = malloc(BUFFER_SIZE + 1 * sizeof(char)); // malloc para reservar el buffer_size
	if (!read_line)
		return (NULL);
	if (*buffer == NULL) // si buffer esta vacio, pprimera llamada, por ejemplo ponemos cadena vacia, para evitar errores en el strjoin
		*buffer = ft_strdup("");
	// line = extract_lines(fd, read_line, *buffer);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_line, BUFFER_SIZE); // leemos el archivo
		if (bytes_read < 0)							   // control de errores si bytes read es -1
		{
			free(read_line); // revisar estos free
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		read_line[bytes_read] = '\0'; // finalizamos la cadena
		*buffer = ft_strjoin(*buffer, read_line);
		if ((temporal = ft_strchr(*buffer, '\n')))
		{
			line = ft_substr(*buffer, 0, ft_strlen(*buffer) - ft_strlen(temporal) + 1);
			temporal = ft_strdup(temporal + 1); // temporal +1
			free(read_line);
			free(*buffer);
			*buffer = temporal;
			return (line);
		}
		if (bytes_read == 0)
			break;
	}
	if (*buffer && **buffer != '\0')
	{
		line = ft_strdup(*buffer);
		free(read_line); // loss 5 de 5
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	free(read_line);
	line = NULL;
	return (line);
}
/*	Control de errores
Checkear el fd, los valores de la tabla de fd son siempre positivos
Checkear el BUFFER_SIZE, el tamaño del buffer siempre tiene que se mayor que 0
para poder escribir en el algo
Checkear los permisos, read puede devolver 0 si mandas leer un archivo y tienes permisos
si no tuviera permisos devolveria -1 y asi se controla el error
*/

char *get_next_line(int fd)
{
	static char *buffer = NULL;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
		return (NULL);
	line = read_line(fd, &buffer);
	if (!line && buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (line);
}

int main(void)
{
	int file_descriptor;
	char *gnl;

	file_descriptor = open("hello.txt", O_RDONLY);

	if (file_descriptor < 0)
	{
		printf("Error");
		return (1);
	}
	while ((gnl = get_next_line(file_descriptor)) != NULL)
	{
		printf("%s", gnl);
		free(gnl);
	}
	close(file_descriptor);
	return (0);
}