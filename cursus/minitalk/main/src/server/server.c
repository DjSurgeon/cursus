/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:04:25 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/12 14:29:59 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	handler_signs(int signum, siginfo_t *info, void *context)
{
	static int				bit_count;
	static unsigned char	c;

	bit_count = 0;
	c = 0;
	(void)context;
	(void)info;;
}

int main(void)
{
	pid_t 	pid;

	pid = getpid();
	printf("Welcome to the minitalk 42 cursus project\n");
	printf("The PID is [%d]\n", (int)pid);
	printf("How to use the client?\n");
	printf("./client <PID> <Message>\n");
	exit(EXIT_SUCCESS);
}