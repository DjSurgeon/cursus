/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:33:36 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/03/10 15:51:31 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **buffer)
{
	/*	Lectura del archivo
	Reservar memoria para la linea leida, hacemos un malloc, para guardar cada vez que ejecutamos read
	del tamaño + 1 para finalizar la cadena
	Leemos el archivo en partes del tamaño dado (BUFFER_SIZE), hasta encontrar un salto de linea
	*/
	
	char	*read_line;		// buffer temporal para leer el archivo
	char	*temporal;		// puntero temporal ara el rest despues de \n
	char	*line;			// linea a devolver
	char	*read_buffer;	// 
	int		bytes_read;		// numero de bytes leidos por read
	
	read_line = malloc(BUFFER_SIZE + 1 * sizeof(char)); // malloc para reservar el buffer_size
	if (!read_line)
		return (NULL);
		
	if (*buffer == NULL)	// si buffer esta vacio, pprimera llamada, por ejemplo ponemos cadena vacia, para evitar errores en el strjoin
		*buffer = ft_strdup("");
		
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_line, BUFFER_SIZE);	// leemos el archivo
		if (bytes_read < 0)	// control de errores si bytes read es -1
		{
			free(read_line); // revisar estos free
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		
		read_line[bytes_read] = '\0'; // finalizamos la cadena
		
		read_buffer = ft_strjoin(*buffer, read_line);
		if ((temporal = ft_strchr(read_buffer, '\n')))
		{
			line = ft_substr(read_buffer, 0, ft_strlen(read_buffer) - ft_strlen(temporal) + 1);
			temporal = ft_strdup(temporal + 1); // temporal +1
			*buffer = temporal;
			return (line);
		}
		if (bytes_read == 0)
		{
			break;
		}
	}
	if (*buffer && **buffer != '\0')
	{
		line = ft_strdup(*buffer);
		free(read_line);	//loss 5 de 5
		free(*buffer);
		*buffer = NULL;
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
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = read_line(fd, &buffer);
	return (line);
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