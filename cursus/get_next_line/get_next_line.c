/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:03:42 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/10 12:26:24 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	add_to_buffer(char *dynamic_buffer, char *buffer)
{
	if (!dynamic_buffer || !buffer)	// control de errores
		return ;
	dynamic_buffer = malloc(buffer);	// reservar memoria para el nodo
	if (!dynamic_buffer)
		return ;
	dynamic_buffer = ft_strlcat(dynamic_buffer, buffer, ft_strlen(buffer));
}

static void	find_line(char *dynamic_buffer, int fd)
{
	char	*buffer;
	int		bytes;

	while (!(ft_strchr(*dynamic_buffer, '\n')))
	{
		buffer = malloc (BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (buffer);
			return ;
		}
		if (bytes == 0)
		{
			free (buffer);
			return ;
		}
		buffer[bytes] = '\0';
		add_to_buffer(dynamic_buffer, buffer);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;                  // Cuando tengamos la linea completa la devolveremos
	static char	*dynamic_buffer;   	      		// variable estatica que guardara la linea

	*dynamic_buffer = NULL;
	*line = NULL;
	if (fd < 0)
		return (NULL);
	find_line(dynamic_buffer, fd);
	
	return (line);
}

#include <stdio.h>

int	main(void)
{
	char	*file_name = "example.txt";
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		return (-1);
	}
	else
	{
		get_next_line(fd);
	}
	close(fd);

	return (0);
}