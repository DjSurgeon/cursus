/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:03:12 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/05 15:33:16 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	En este ejemplo, vamos a buscar el carácter \n el salto de linea 
**	voy a utilizar la funcion f_strchr que busca la primera coincidencia de un char
**	en una cadena.
**	primero abro el archivo, hay dos lineas, por lo tanto tengo que devolver la 2
**	hago un read durante el cual leo el 
*/

#include <unistd.h>
#include <stdio.h>

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

#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char		*result;
//	const char	*example = "hi 42 \nhola 42";
	char		to_find = '\n';
	
//	printf("%s\n", example);
//	printf("%s\n", result);
	
	char		*file_name = "hello.txt";
	char		buffer[42];
	int			fd;

	fd = open(file_name, O_RDONLY);
	
	if (fd == -1)
	{
		printf("Error\n");
		return (-1);
	}
	read(fd, buffer, sizeof(buffer));
	result = ft_strchr(buffer, (int)to_find);
	printf("%s\n", result);
	printf("=============================\n");
	printf("%s\n", buffer);
	return (0);
}
