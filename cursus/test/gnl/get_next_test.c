/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:04:24 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/06 16:22:21 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*dynamic_buffer(size_t size)
{
	char	*dynamic_buffer;
	
	dynamic_buffer = malloc(size * sizeof(char *));
	if (!dynamic_buffer)
		return (NULL);
	return (dynamic_buffer);
}
/*********************************************/
char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	buffersize;
	
	*buffer = dynamic_buffer(buffer);
	read(fd, buffer, buffersize);

	return (buffer);
}

int main(void)
{
	char	*file_name = "hello.txt";
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
	
	return (0);
}