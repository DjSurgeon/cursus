/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:15:42 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/03/05 14:45:28 by sergio-jime      ###   ########.fr       */
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
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len]);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_substring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		new_substring = malloc(1);
		if (!new_substring)
			return (NULL);
		new_substring[0] = '\0';
		return (new_substring);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new_substring = ft_calloc(1, len + 1);
	if (!new_substring)
		return (NULL);
	while (i < len)
	{
		new_substring[i] = s[start + i];
		i++;
	}
	return (new_substring);
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

char	*get_next_line(int fd)
{
	int			bytes_read;
	int			buffer_size = 1;
	char		*read_buffer;
	char		*temporal;
	char		*return_line;
	static char	*line = NULL; // inicializacion de la variable estatica

	// Memoria para el buffer de lectura
	read_buffer = ft_calloc(buffer_size + 1, sizeof(char));
	if (read_buffer == NULL)
	return (NULL);

	// Si line es NULL la primera llamada o tras imprimir una linea, se inicizaliza a cadena vacia para evitar problemas en el join
	if(!line)
		line = ft_calloc(1, sizeof(char)); // evitamos pasar un valor null a strjoin
	if (!line)
	{
		free(read_buffer);
		return (NULL);
	}

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, buffer_size);
		if (bytes_read < 0) // si hay algun error leyendo devolvemos null
		{
			free(read_buffer);
			free(line);
			line = NULL;
			return (NULL);
		}
		line = ft_strjoin(line, read_buffer); // vamos acumulando en la linea
		// Vamos a buscar el final de linea en lo acumulado
		if ((temporal = ft_strchr(line, '\n')))
		{
			// return_line = ft_calloc(1, sizeof(char));
			return_line = ft_substr(line, 0, temporal - line + 1);
			temporal = ft_strdup(temporal + 1);
			free(line);
			line = temporal;
			free(read_buffer);
			return(return_line);
		}
	}
	free (read_buffer);
	if(line && *line != '\0')
	{
		return_line = ft_strdup(line);
		free(line);
		line = NULL;
		return (return_line);
	}
	free (line);
	line = NULL;
	return (NULL);
}
int main (void)
{
	int		file_descriptor;
	char	*line;

	file_descriptor = open("example2.txt", O_RDONLY);
	if (file_descriptor == -1)
	{
		printf("Error");
		return(1);
	}
	while ((line = get_next_line(file_descriptor)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(file_descriptor);
	return (0);
}