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

/**
** @brief Signal handler for reconstructing bytes from incoming signal bits.
** @param signum The signal received (SIGUSR1 for bit 0, SIGUSR2 for bit 1).
** @param info Pointer to siginfo_t containing details about the signal sender.
** @param context User context (unused).
**
** Reconstructs characters bit-by-bit. Once 8 bits are received, the completed
** character is written immediately to standard output. If the character is '\0',
** a newline is written.
** After processing each bit, the handler sends a confirmation signal (SIGUSR1)
** back to the client's process ID.
**
** @note Maintains a static buffer for the current char, bit count, and sender PID.
** Uses O(1) memory and is completely async-signal-safe.
*/
static void	handler_signs(int signum, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_count = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (info->si_pid != client_pid)
	{
		current_char = 0;
		bit_count = 0;
		client_pid = info->si_pid;
	}
	current_char = (current_char << 1);
	if (signum == SIGUSR2)
		current_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		current_char = 0;
		bit_count = 0;
	}
	if (info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
}

/**
** @brief Entry point for the minitalk server program.
**
** Sets up the sigaction configuration for SIGUSR1 and SIGUSR2, ensuring
** that the signals are blocked while the handler is executing to prevent reentrancy.
** Prints its own Process ID (PID) and runs in an infinite loop waiting for signals.
**
** @return EXIT_SUCCESS if terminated normally, or exits on error.
*/
int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = handler_signs;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
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
