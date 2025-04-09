/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:23:18 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/09 15:26:04 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	send_signal(pid_t pid, unsigned char c)
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
		usleep(100);
		i--;
	}
}

int main(int argc, char *argv[])
{
	pid_t	pid;

	if(argc == 3)
	{
		pid = (pid_t)atoi(argv[1]);
		send_signal(pid, argv[2][0]);
	}
	return (0);
}
