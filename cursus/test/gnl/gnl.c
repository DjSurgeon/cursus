/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:39:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/10 15:25:06 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer)
{
	char	*line;
	char	*read_buffer;
	int		bytes_read;

	read_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!read_buffer)
		return (NULL);
	if (buffer == NULL);
		buffer = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		read_buffer[bytes_read] = '\0';
		if (bytes_read < 0)
		{
			line = ft_strjoin(buffer, read_buffer);
		}
		if (bytes_read == 0)
			break;
	}
	
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return(NULL);
	buffer = read_line(fd, buffer); // Leer durante el buffer size hasta \n o EOF
	if (!buffer)
		return (NULL);
	line = // TODO: Extraer la linea a devolver(fd, buffer);
	next_line = // TODO: Lo sobrante meterlo en el buffer(fd, buffer);
	buffer = next_line;
	return(line);
}

int main(void)
{
	int		fd;
	char	*gnl;

	fd = open("hello.txt", O_RDONLY);

	while (gnl = get_next_line(fd) != NULL)
	{
		printf("%s", gnl);
		free(gnl);
	}
	close(fd);
	return (0);
}