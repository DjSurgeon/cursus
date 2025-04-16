/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:23:18 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/16 12:24:55 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void send_length(pid_t pid, unsigned int len)
{
	int i;
	int bit;

	i = 31;
	while (i >= 0)
	{
		bit = (len >> i) & 1;
		if(bit == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(500);
		i--;
	}
	
}

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
		len = ft_strlen(argv[2]);
		send_length(pid, len);
		while (argv[2][i] != '\0')
		{
			send_signal(pid, argv[2][i]);
			i++;
		}
		send_signal(pid, '\0');
	}
	return (0);
}
