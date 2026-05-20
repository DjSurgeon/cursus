/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 13:45:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2026/05/20 13:45:00 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
** @brief Global volatile flag to synchronize signals between client and server.
*/
volatile sig_atomic_t	g_ack_received = 0;

/**
** @brief Signal handler for receiving acknowledgement from the server.
** @param signum The signal received (expected to be SIGUSR1).
**
** Sets the global volatile flag `g_ack_received` to 1 to notify the
** transmission loop that the server has successfully received the last bit.
*/
static void	ack_handler(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

/**
** @brief Sends an unsigned character bit-by-bit to a server process.
** @param pid The process ID (PID) of the target server.
** @param c The character (byte) to send.
**
** Iterates through all 8 bits of the character (from MSB to LSB).
** For each bit:
** - Sends SIGUSR1 if the bit is 0.
** - Sends SIGUSR2 if the bit is 1.
** - Blocks and waits using sigsuspend until the server sends back a
**   SIGUSR1 confirmation signal.
**
** @note Relies on the global variable `g_ack_received` for synchronization.
** @warning Exits the program with EXIT_FAILURE if the kill call fails.
*/
static void	send_signals(pid_t pid, unsigned char c)
{
	int			i;
	int			bit;
	sigset_t	empty_mask;

	sigemptyset(&empty_mask);
	i = 7;
	while (i >= 0)
	{
		g_ack_received = 0;
		bit = (c >> i) & 1;
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		while (!g_ack_received)
		{
			sigsuspend(&empty_mask);
		}
		i--;
	}
}

/**
** @brief Entry point for the minitalk client program.
** @param argc Argument count.
** @param argv Argument vector: argv[1] is server PID, argv[2] is the message.
**
** Configures the SIGUSR1 action to receive acknowledgements, blocks SIGUSR1
** during execution to prevent signal loss/race conditions, parses the server PID,
** and transmits the message character-by-character (including the NULL terminator).
**
** @return EXIT_SUCCESS upon successful execution, or exits with EXIT_FAILURE/error messages.
*/
int	main(int argc, char *argv[])
{
	pid_t				pid;
	int					i;
	struct sigaction	sa;
	sigset_t			block_mask;

	if (argc == 3)
	{
		sa.sa_handler = ack_handler;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			exit(EXIT_FAILURE);
		sigemptyset(&block_mask);
		sigaddset(&block_mask, SIGUSR1);
		sigprocmask(SIG_BLOCK, &block_mask, NULL);
		pid = (pid_t)ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i] != '\0')
		{
			send_signals(pid, (unsigned char)argv[2][i]);
			i++;
		}
		send_signals(pid, '\0');
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("How to use the client?\n", 2);
		ft_putstr_fd("./client <PID> <Message>\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
