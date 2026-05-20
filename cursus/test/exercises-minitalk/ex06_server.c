/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:39:05 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/16 14:57:34 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	handler_signs(int signum, siginfo_t *info, void *context)
{
	static	int bit_count = 0;
	static	unsigned char c = 0;

	(void)context;
	(void)info;
	c = c << 1;
	if(signum == SIGUSR2)
		c |= 1;
	bit_count++;
	if(bit_count == 8)
	{
		// TODO Procesar los bits y la longitud
		
		if (c == '\0')
		{
			write(1, "\0\n", 2);
		}
		else
		{
			write(1, &c, 1);
		}
		bit_count = 0;
		c = 0;
	}
}

int main(void)
{
	pid_t	pid;
	struct sigaction sa;

	pid = getpid();
	printf("The PID of the process is: %i\n", (int)pid);
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
