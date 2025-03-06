/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:35:55 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/05 10:28:41 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	j = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new_string = ft_calloc(1, size_s1 + size_s2 + 1);
	if (!new_string)
		return (NULL);
	while (i < size_s1)
	{
		new_string[i] = s1[i];
		i++;
	}
	while (j < size_s2)
	{
		new_string[i + j] = s2 [j];
		j++;
	}
	return (new_string);
}

char	*ft_strdup(const char *s)
{
	char	*new_string;
	size_t	s_size;
	size_t	i;

	i = 0;
	s_size = ft_strlen(s);
	new_string = ft_calloc(1, s_size + 1);
	if (!new_string)
		return (NULL);
	while (i < s_size)
	{
		new_string[i] = s[i];
		i++;
	}
	return (new_string);
}

static char *read_bytes_from_file(int fd)
{
	int			bytes_read;
	int			nbytes;
	char		*read_buffer;
	static int	count = 1;
	static char	*total_buffer = NULL;

	nbytes = 3;
	printf("ft_calloc -> [%i] -- ", count++);
	read_buffer = ft_calloc(nbytes + 1, sizeof(char));	//reservamos memoria y se actualiza a 0
	if (read_buffer == NULL)
		return (NULL);
	bytes_read = read(fd, read_buffer, nbytes);			//lectura de 3 bytes
	if (bytes_read <= 0)								// Si el archivo esta vacio
	{
		free(read_buffer);
		return (NULL);
	}
	if (total_buffer) {
		total_buffer = ft_strjoin(total_buffer, read_buffer);
	}
	else
		total_buffer = ft_strdup(read_buffer);
	free (read_buffer);
	return (total_buffer);
}

char	*get_next_line(int fd)
{
	char	*get_next_buffer;

	get_next_buffer = read_bytes_from_file(fd);
	return (get_next_buffer); 
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