/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:30:47 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/19 18:13:28 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signals(pid_t pid, unsigned char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = (pid_t)ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_signals(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		printf("Error\n");
		printf("How to use the client?\n");
		printf("./client <PID> <Message>\n");
	}
	send_signals(pid, '\0');
	exit(EXIT_SUCCESS);
}
