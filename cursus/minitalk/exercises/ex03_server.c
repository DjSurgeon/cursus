/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:31:09 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/08 15:55:27 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Crea dos programas en C. El primero actuará como servidor, el cual establece un manejador para SIGUSR1 que imprima un mensaje cuando la señal sea recibida. El segundo programa actuará como cliente y enviará la señal SIGUSR1 al servidor. El cliente recibirá el PID del servidor como argumento de línea de comandos.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/*
Definición de la función sigaction
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
- signum: El número de señal a manejar (como SIGUSR1, SIGUSR2)
- act: Un puntero a una estructura que especifica la nueva acción para la señal
- oldact: Un puntero donde se almacenará la acción anterior (puede ser NULL si no interesa)

Estructura sigaction
struct sigaction {
	void		(*sa_handler)(int);							Manejador de señal
	void		(*sa_sigaction)(int, siginfo_t *, void *);	Manejador alternativo
	sigset_t	sa_mask;									Señales a bloquear durante el manejador
	int			sa_flags;									Flags que modifican el comportamiento
	void		(*sa_restorer)(void);						No se utiliza en aplicaciones modernas
};
*/

/* Manejador SIGUSR1 */
/* El manejador se ejecuta cuando reciba una señal */
void	handler_sigusr1(int signum,  siginfo_t *info, void *context)
{
	(void) context;
	if(signum == SIGUSR1)
		printf("\nThe signal is ON\n");
	if(info != NULL)
		printf(" PID: %i", info->si_pid);
}

int main(void)
{
	// tipo de dato pid_t
	pid_t pid;
	// declaración de la estructura
	struct sigaction sa;

	pid = getpid();
	printf("The PID of the process is: %i\n", (int)pid);

	// inicialización de la mascara de señales a 0 (conjunto vacio)
	sigemptyset(&sa.sa_mask);
	// manejador de señal
	sa.sa_handler = handler_sigusr1;
	// especificamos el manejador con información extendida
	sa.sa_flags = 0;

	// Manejador
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		perror("Error sigaction\n");
	// bucle esperando señales
	while (1)
		pause();
	return (0);
}
