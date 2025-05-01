/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:04:25 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/05/01 18:03:50 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_buffer	g_buffer = {0};

static void	reset_buffer(void)
{
	free(g_buffer.str);
	g_buffer.str = ft_strdup("");
	g_buffer.bit_count = 0;
	g_buffer.current_char = 0;
	g_buffer.client_pid = 0;
}

static void	get_str(void)
{
	char	temp[2];
	char	*result;

	if (g_buffer.current_char == '\0')
	{
		write(1, g_buffer.str, ft_strlen(g_buffer.str));
		write(1, "\n", 1);
		reset_buffer();
	}
	else
	{
		temp[0] = g_buffer.current_char;
		temp[1] = '\0';
		result = ft_strjoin(g_buffer.str, temp);
		free(g_buffer.str);
		g_buffer.str = result;
	}
	g_buffer.bit_count = 0;
	g_buffer.current_char = 0;
}

static void	handler_signs(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_buffer.client_pid != info->si_pid)
	{
		reset_buffer();
		g_buffer.client_pid = info->si_pid;
	}
	g_buffer.current_char = (g_buffer.current_char << 1);
	if (signum == SIGUSR2)
		g_buffer.current_char |= 1;
	g_buffer.bit_count++;
	if (g_buffer.bit_count == 8)
	{
		get_str();
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = handler_signs;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	ft_putstr_fd("Welcome to the minitalk 42 cursus project\n", 1);
	ft_putstr_fd("The PID is: ", 1);
	ft_putnbr_fd((int)pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("How to use the client?\n", 1);
	ft_putstr_fd("./client <PID> <Message>\n", 1);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
