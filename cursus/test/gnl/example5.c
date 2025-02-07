/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:55:34 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/06 15:52:58 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

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

/* int	read_buffer(int fd, char *buffer, size_t sizeofbuffer)
{
	static char	*read_buffer;
	char	*next_buffer;

	if (fd == -1)
		return (-1);
	else
	{
		read_buffer = open(fd, buffer, sizeofbuffer);
		if (next_buffer = ft_strchr(read_buffer, '\n'))
		{
			read_buffer = next_buffer;
		}
		else
		{
			read_buffer;
		}
		
	}
} */




int main(void)
{
	char	*file_name = "hello.txt";
	char	*buffer;
	char static	*tempbuffer;
	int		fd;
	int		bytes;
	size_t	BUFFER_SIZE = 42;
	
	fd = open(file_name, O_RDONLY);
	
	if (fd == -1)
	{
		printf("Error File Descriptor no valido o no encontrado\n");
		return (-1);
	}
	printf("%i\n", fd);
	if (fd > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		tempbuffer = buffer;
		
		while (bytes > 0)
		{
			printf("%s\n", tempbuffer);
			printf("Se han leido %i bytes\n", bytes);
			*buffer++;
		}
		//printf("Se han leido %i bytes\n", bytes);
		//printf("%s\n", buffer);
		return(0);
	}
	else 
	{
	printf("End of File / EOF. Has llegado al final del archivo\n");	
	}
	close(fd);
	return (0);
}