/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:12:05 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/08/30 08:38:48 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

/// @brief Execute a given command inside a child process
/// @note 'args': separate multiple arguments in a command;
/// 'env_arr': save 'envlist' as an array;
/// 'cmd': the full path from the given command string
/// @warning Hay que hacer free de 'env_arr' por si falla execve(), que no debería
/// por haber sido chequeado con access().
/// Duda para el futuro: execve() toma como parámetro un **envp. Si valiese con 
/// con sólo la string de "PATH=...", podríamos desechar la necesidad de pasar de
/// 'envlist' a 'env_arr', y recuperar de la lista el valor de "PATH=..."
void	execute_command(char *cmd_str, t_env **envlist)
{
	char	**args;
	char	*cmd;
	char	**env_arr;

	env_arr = envlist_to_arr(envlist);
	if (!env_arr)
		return ;
	args = ft_split(cmd_str, ' ');
	if (!args || !args[0])
	{
		ft_free_array(env_arr);
		return ;
	}
	cmd = ft_check_path(args[0], env_arr);
	if (!cmd)
		cmd_not_found(args[0], args);
	execve(cmd, args, env_arr);
	perror("execve");
	ft_free_array(args);
	ft_free_array(env_arr);
	free(cmd);
	exit (1);
}

/// @brief Initiate a child process to execute a given command
void	command_in(char *command, t_env **environment)
{
	pid_t		pid;

	pid = fork();
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
		execute_command(command, environment);
	waitpid(pid, NULL, 0);
	return ;
}
