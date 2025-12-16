/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:26:50 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/08/27 11:50:30 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	safe_close(int fd)
{
	if (fd > 2)
		close(fd);
}

void	ft_close_two(int fd1, int fd2)
{
	safe_close(fd1);
	safe_close(fd2);
	return ;
}

void	ft_close_three(int fd1, int fd2, int fd3)
{
	safe_close(fd1);
	safe_close(fd2);
	safe_close(fd3);
	return ;
}

int	ft_wait_and_exit(pid_t last_pid)// esta parte recupera la señal del último proceso hijo. Réplica de: echo $?
{
	int	status;
	pid_t	pid;

	while ((pid = wait(&status)) > 0) //esperamos a todos los hijos
	{
		if (pid == last_pid) // pero sólo recuperamos el id del último
		{// Ahora usamos macros para extraer el código de salida de un proceso hijo:
			if (WIFEXITED(status))//se ha salido normalmente?
				return (WEXITSTATUS(status));
			else if (WIFSIGNALED(status))//o se ha terminado con señal?
				return (128 + WTERMSIG(status));//qué señal?
		}
	}
	exit(EXIT_FAILURE); // Si no conseguimos capturar el último hijo por alguna razón
}

/// @brief Pipe manager:
/// @param args array of splited by '|' commands
/// @param blocks number of blocks of commands with their parameters
/// @param in FD to read from at start
/// @param out FD to write to at the end of the chain
int	pipes(char **args, int blocks, t_env **env_list, int in, int out)
{
	int		i;
	int		prev_pipe;
	int		pipe_fd[2];
	pid_t	pid;
	pid_t	last_pid;

	prev_pipe = -1;
	last_pid = -1;
	i = 0;
	while (i < blocks)
	{
		if (i < blocks - 1 && pipe(pipe_fd) == -1) // si no estamos en el último comando(blocks -1), necesitamos pipe
			return (perror("pipe"), EXIT_FAILURE);
		pid = fork();
		if (pid < 0)
			return (perror("fork"), EXIT_FAILURE);
		if (pid == 0) //proceso hijo
		{
			if (i == 0)//si es el primero, usar in
			{
				if (dup2(in, 0) == -1)
					return (perror("dup2 in"), EXIT_FAILURE);
			}
			else//si no, usar anterior pipe
			{
				if (dup2(prev_pipe, 0) == -1)
					return (perror("dup2 in"), EXIT_FAILURE);
			}
			if (i == blocks - 1)
			{
				if (dup2(out, 1) == -1)// si es el último comando, escribir en out
					return (perror("dup2 in"), EXIT_FAILURE);
			}
			else
			{
				if (dup2(pipe_fd[1], 1) == -1)// si no, escribir en pipe actual para que el siguiente proceso lo lea
					return (perror("dup2 in"), EXIT_FAILURE);
			}
			ft_close_three(in, out, prev_pipe);
			if (i < blocks - 1)//si no estamos en el último comando, cerrar pipe actual
				ft_close_two(pipe_fd[0], pipe_fd[1]);
			execute_command(args[i], env_list);
		} // a partir de aquí proceso padre
		last_pid = pid;
		safe_close(prev_pipe); //cerrar descriptor que ya ha heredado el hijo
		if (i < blocks - 1)
		{
			close(pipe_fd[1]); //ya hemos escrito aquí
			prev_pipe = pipe_fd[0]; //de aquí leerá el próximo comando
		}
		else
		{
			if (pipe_fd[0] != -1 && pipe_fd[1] != -1)
				ft_close_two(pipe_fd[0], pipe_fd[1]);// Último comando, ya no necesitamos pipe_fds
		}
		i++;
	}
	ft_close_two(in, out);
	return (ft_wait_and_exit(last_pid));
}
