/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:17:17 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/03/13 00:14:58 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*clean_buffer(char *buffer)
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
	return(NULL);
}

char	*extract_line(char *buffer)
{
	char	*line;
	char	*temp;

	temp = ft_strchr(buffer, '\n');
	if (temp)
	{
		line = ft_substr(buffer, 0, ft_strlen(buffer) - ft_strlen(temp) + 1);
	}
	else
	{
		line = ft_strdup(buffer);
	}
	return (line);
}

char	*read_line(int fd,char **buffer)
{
	char	*buffer_read;
	int		bytes_read;
	char	*temp;

	buffer_read = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer_read)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer_read, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer_read), NULL);
		buffer_read[bytes_read] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(temp, buffer_read);
		free(temp);
		if (ft_strchr(*buffer, '\n') || bytes_read == 0)
		{
			free (buffer_read);
			break;
		}
	}
	return (*buffer);
}

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
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}

int main(void)
{
	char	*gnl;
	//int		fd;

	// fd = open("hp.txt", O_RDONLY);
	while ((gnl = get_next_line(1)) != NULL)
	{
		printf("%s", gnl);
		free(gnl);
	}
	//close(fd);
	return (0);
}
