/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:23:18 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/16 15:02:47 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void	send_signal(pid_t pid, unsigned char c)
{
	int	i;
	int bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;
	int		len;

	i = 0;
	if(argc == 3)
	{
		pid = (pid_t)atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_signal(pid, argv[2][i]);
			i++;
		}
		send_signal(pid, '\0');
	}
	return (0);
}
