/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:30:47 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/12 15:10:11 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	send_signals(pid_t pid, unsigned char c)
{
	int	i;
	int bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if(bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int main(int argc, char *argv[])
{
	(void)argv;
	if(argc == 3)
	{
		//TODO process the message
		pid = (pid_t)atoi(argv[1]);
		send_signals(pid, argv[2][0]);
	}
	else
	{
		printf("Error\n");
		printf("How to use the client?\n");
		printf("./client <PID> <Message>\n");
	}
	exit(EXIT_SUCCESS);
}