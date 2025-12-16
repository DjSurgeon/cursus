/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:17:17 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/17 14:17:38 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	Description: Cleans the buffer by extracting the remaining content after
	a newline.
**	Parameters:
**	- buffer: A pointer to the buffer containing the read data.
**	Return:
**	- A new string with the content after the newline, or NULL if no newline
	is found.
**	- Frees the original buffer.
*/

static char	*clean_buffer(char *buffer)
{
	char	*temp;
	char	*line;

	temp = ft_strchr(buffer, '\n');
	if (temp)
	{
		line = ft_strdup(temp + 1);
		free(buffer);
		return (line);
	}
	free(buffer);
	return (NULL);
}

/*
**	Description: Extracts a line from the buffer up to the newline character.
**	Parameters:
**	- buffer: A pointer to the buffer containing the read data.
** Return:
**	- A new string containing the line up to and including the newline
	or the entire buffer if no newline is found.
*/

static char	*extract_line(char *buffer)
{
	char	*line;
	char	*temp;

	temp = ft_strchr(buffer, '\n');
	if (temp)
		line = ft_substr(buffer, 0, ft_strlen(buffer) - ft_strlen(temp) + 1);
	else
		line = ft_strdup(buffer);
	return (line);
}
/*
**	Description: Reads from the file descriptor and accumulates data in the
	buffer until a newline or EOF is found.
**	Parameters:
**	- fd: The file descriptor to read from.
**	- buffer: A pointer to the static buffer to accumulate data.
**	Return:
**	- The updated buffer with the new data read, or NULL if an error occurs.
*/

static bool	read_line(int fd, char **buffer)
{
	char	*buffer_read;
	int		bytes_read;
	char	*temp;

	buffer_read = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer_read)
		return (false);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer_read, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer_read), false);
		buffer_read[bytes_read] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(temp, buffer_read);
		free(temp);
		if (ft_strchr(*buffer, '\n') || bytes_read == 0)
		{
			free(buffer_read);
			break ;
		}
	}
	return (true);
}
/*
**	Description: Reads the next line from a file descriptor.
**	Parameters:
**	- fd: The file descriptor to read from.
**	Return:
**	- A string containing the next line, or NULL if there are no more
	lines or an error occurs.
*/

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (!read_line(fd, &buffer) || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}
