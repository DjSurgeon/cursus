/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:39:05 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/09 15:39:43 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	handler_signs(int signum, siginfo_t *info, void *context)
{
	static	bit_count = 0;
	static	unsigned char c = 0;

	(void)context;
	(void)info;
	c = c << 1;
	if(signum == SIGUSR2)
		c |= 1;
	bit_count++;
	if(bit_count == 8)
	{
		printf("%c\n", (char)c);
		bit_count = 0;
		c = 0;
		// if(info != NULL)
		// 	printf("\nPID: %i", info->si_pid);
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
