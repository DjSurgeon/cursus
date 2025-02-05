/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:20:38 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/05 14:50:20 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char	*file_name = "hello.txt";	//nombre del archivo que queremos leer
	int		fd;
	int		bytes_read;

	fd = open(file_name, O_RDONLY);		// abrimos el archivo con open y guardamos su fd
	
	if (fd == -1)						// verificamos que existe el fd y que open ha echo su trabajo
	{
		printf("Error\n");
		return(1);
	}
	else
		printf("Succes\n");

	char	buffer [32];

	bytes_read = read(fd, buffer, sizeof(buffer));	//nos va a indicar cuanto bytes son leidos

	printf("%d Bytes read.\n" , bytes_read);		
	printf("File contents: \n%s\n", buffer);		// nos imprime el contenido del fd

	return (0);
}
