/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:35:55 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/04 17:27:58 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total_size;
	void			*memory_pointer;
	unsigned char	*clean_memory;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	memory_pointer = malloc(total_size);
	if (!memory_pointer)
		return (NULL);
	clean_memory = (unsigned char *)memory_pointer;
	i = 0;
	while (i < total_size)
	{
		clean_memory[i] = 0;
		i++;
	}
	return (clean_memory);
}

char	*get_next_line(int fd)
{
int		bytes_read;
int		nbytes;
char	*read_buffer;
static int count = 1;

nbytes = 3;
printf("ft_calloc -> [%i]\n", count++);
read_buffer = ft_calloc(nbytes + 1, sizeof(char));	//reservamos memoria y se actualiza a 0
if (read_buffer == NULL)
	return (NULL);
printf("buffer de calloc [%s]\n", read_buffer);
bytes_read = read(fd, read_buffer, nbytes);			//lectura de 3 bytes
printf("Bytes leidos -> [%i]\n", bytes_read);
if (bytes_read <= 0)								// Si el archivo esta vacio
{
	free(read_buffer);
	return (NULL);
}
return (read_buffer);
}

int main (void)
{
	int		fd;
	char	*read_buffer;

	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error!! No se pudo abrir el archivo");
		return (1);
	}
	else
	{
		while (1)
		{
		read_buffer = get_next_line(fd);
		printf("Buffer leido => %s\n", read_buffer);
		free (read_buffer);
		if (read_buffer == NULL)
			return (0);
		}
	}

// printf("Número de bytes leidos => 	%i\n", bytes_read);

free(read_buffer);
close(fd);

return (0);
}