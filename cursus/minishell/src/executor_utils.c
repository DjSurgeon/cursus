/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:09:35 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/08/27 18:24:04 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief Manage invalid command sent, finish child process
void	cmd_not_found(char *cmd, char **args)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	ft_free_array(args);
	exit (127) ;
}

/// @brief Separate potential paths from env by spliting with the delimitator ':'
char	**ft_potential_paths(char **envp) //a partir de PATH=, guardar en paths las posibles direcciones accesibles deparadas por ":"
{
	char	**paths;
	int		i;

	i = 0;
	if (!envp[i] || ft_strlen(envp[i]) < 6)
    	return (NULL);
	
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0) //encontrar línea con "PATH="
		i ++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':'); //separar los distintos paths delimitados por :
	return (paths);
}

/// @brief Check potential paths by building the strings (paht + '/' + command)
char	*ft_build_full_path(char *command, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*path;
	int		i;

	full_path = NULL;
	paths = ft_potential_paths(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, command);
		free(path);
		if (access(full_path, X_OK) == 0)
			return (ft_free_array(paths), full_path);
		free(full_path);
		full_path = NULL;
		i ++;
	}
	return (ft_free_array(paths), NULL);
}

/// @brief Get full path from a command string, and check if it can be executed
/// @warning !!! Estás bien al asumir que el usuario pasó una ruta (ej. ./myprog), 
/// pero recuerda: Si es un path relativo, puede necesitar getcwd() para ejecutarse correctamente.
/// Si estás en un entorno tipo minishell, deberías manejar también el caso ~/.
char	*ft_check_path(char *command, char **envp)
{
	char	*full_path;

	full_path = NULL;
	if (ft_strchr(command, '/'))
	{
		full_path = ft_strdup(command);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		else
		{
			free(full_path);
			return (NULL);
		}
	}
	else
	{
		full_path = ft_build_full_path(command, envp);
		return (full_path);
	}
	return (NULL);
}
