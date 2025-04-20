/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:03:06 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/19 17:41:35 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*
**	@brief Checks if a character is a whitespace character
**	@param c Character to check (ASCII value as integer)
**	
**	Verifies if the character is one of the standard whitespace characters:
**	- Space (' ', ASCII 32)
**	- Form feed ('\f', ASCII 12)
**	- Newline ('\n', ASCII 10)
**	- Carriage return ('\r', ASCII 13)
**	- Horizontal tab ('\t', ASCII 9)
**	- Vertical tab ('\v', ASCII 11)
**	
**	@return 1 if whitespace character, 0 otherwise
*/

int	ft_isspace(int c)
{
	if (c == 32 || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static void send_signal(pid_t pid, unsigned char c)
{
	int i;
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
		usleep(200);
		i--;
	}
}

void atob_bitshift(int pid, char c)
{
	int i;
	int bit;

	clock_t start, end;   // #include <time.h>
	double cpu_time_used; // #include <time.h>

	i = 7;
	while (i >= 0)
	{
    start = clock();
		bit = (c >> i) & 1;
		if (bit == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i--;
	
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // Imprime o registra el tiempo empleado
    printf("Tiempo para transferir bit %d: %f segundos\n", i+2, cpu_time_used);
    usleep(100);
	}
}

int main(int argc, char *argv[])
{
	pid_t pid;
	int i;

	i = 0;
	if (argc == 3)
	{
		pid = (pid_t)ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_signal(pid, argv[2][i]);
			atob_bitshift(pid, argv[2][i]);
			i++;
		}
		send_signal(pid, '\0');
	}
	return (0);
}
