/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:32:17 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/08 16:53:29 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void	send_signal(pid_t pid)
{
	if(kill(pid, SIGUSR1) == -1)
		printf("Error\n");
	else
		printf("Signal send");
}

int main(int argc, char *argv[])
{
	pid_t pid;
	if(argc == 2)
	{
		pid = (pid_t)atoi(argv[1]);
		send_signal(pid);
	}
	else
		printf("Use this -> <PID>\n ");
	return (0);
}
