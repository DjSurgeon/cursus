/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:29:50 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/16 11:03:19 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	handler_signs(int signum, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	c = 0;
	static char				*buffer = NULL;
	static size_t			pos = 0;
	static size_t			capacity = 0;

	(void)context;

	// Bit shifting para reconstruir el carácter
	c = c << 1;
	if (signum == SIGUSR2)
		c |= 1;
	bit_count++;

	if (bit_count == 8)
	{
		// Inicializa el buffer si aún no existe
		if (!buffer)
		{
			capacity = 1024;
			buffer = malloc(capacity);
			if (!buffer)
			{
				write(2, "Error: malloc failed\n", 22);
				exit(EXIT_FAILURE);
			}
			pos = 0;
		}

		// Si ya no cabe, redimensiona
		if (pos >= capacity - 1)
		{
			capacity *= 2;
			char *new_buffer = realloc(buffer, capacity);
			if (!new_buffer)
			{
				free(buffer);
				write(2, "Error: realloc failed\n", 23);
				exit(EXIT_FAILURE);
			}
			buffer = new_buffer;
		}

		// Guardar el carácter
		buffer[pos++] = c;

		if (c == '\0') // Fin del mensaje
		{
			write(1, buffer, pos - 1); // No imprimir el '\0'
			write(1, "\n", 1);         // Agregar salto de línea
			free(buffer);
			buffer = NULL;
			capacity = 0;
			pos = 0;
		}

		// Reiniciar para el siguiente carácter
		c = 0;
		bit_count = 0;

		// Enviar ACK al cliente si lo deseas (info->si_pid es el PID del cliente)
		if (info)
			kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	printf("The PID of the process is: %d\n", pid);

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler_signs;
	sa.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &sa, NULL) == -1 ||
		sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error setting sigaction");
		exit(EXIT_FAILURE);
	}

	while (1)
		pause();
	return (0);
}
