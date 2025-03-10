/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:33:36 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/03/10 11:14:08 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **buffer)
{
	char	*read_line;
	char	*temporal;
	char	*line;
	int		bytes_read;

	read_line = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!read_line)
		return (NULL);
	if (*buffer == NULL)
		*buffer = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_line, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(read_line);
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		read_line[bytes_read] = '\0';
		*buffer = ft_strjoin(*buffer, read_line);
		if ((temporal = ft_strchr(*buffer, '\n')))
		{
			line = ft_substr(*buffer, 0, ft_strlen(*buffer) - ft_strlen(temporal) + 1);
			temporal = ft_strdup(temporal + 1);
			free(*buffer);
			*buffer = temporal;
			free(read_line);
			return (line);
		}
		if (bytes_read == 0)
			break ;
	}
	free(read_line);
	if (*buffer && **buffer != '\0')
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	line = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
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

	file_descriptor = open("example2.txt", O_RDONLY);

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
