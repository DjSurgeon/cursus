/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:17:17 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/22 18:31:12 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/**
 * @file get_next_line.c
 * @brief Read from file descriptor and accumulates data in buffer.
 * Performs buffered reading from a file descriptor, accumulating data
 * until either:
 * - A new line character is found.
 * - EOF is reached.
 * - An error occurs.
 * @note Dynamically manages buffer growth using ft_strjoin.
 * @note Ensures proper null-termination os accumulated data.
 * @note Uses BUFFER_SIZE for chunked reading.
 * @param fd Valid file descriptor to read from.
 * @param buffer Pointer to the static buffer accumulating data between calls.
 * @return bool true if reading succeds (newline found or EOF reached),
 * false if any error occurs (with proper cleanup).
 * @warning The file descriptor must be valid and readable.
 * @warning The buffer pointer must be properly initializaed.
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

/**
 * @file get_next_line.c
 * @brief Reads the next line from a file descriptor.
 * Reads from a file descriptor until a newline is encountered or EOF
 * is reached, maintaining state between calls using a static buffer.
 * The function:
 * - Handles files descriptor validation.
 * - Manages memory allocation and cleanup.
 * - Preserves remaining buffer content between calls.
 * - Support configurable BUFFER_SIZE
 * @note The returned string must be freed by the caller.
 * @note Properly handles edge cases (empty lines, EOF without newline).
 * @param fd Valid file descriptor to read from.
 * @return char* On success: Dynamically allocated string containing the line
 * (including newline if present), on failure or EOF : NULL (with all
 * resources cleanup).
 * @code
 * // Example
 * int fd = open("file.txt", O_RDONLY);
 * char *line;
 * while((line = get_next_line(fd)) != NULL)
 * {
 * 	ft_printf("%s", line);
 * 	free(line);
 * }
 * close(fd);
 * @endcode
 * @warning Requires BUFFER_SIZE to be defined.
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
