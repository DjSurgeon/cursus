/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:49:50 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/08/26 13:54:53 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO funcion que busque variables, añadir o modificar variable, 
// eleminar variables, gestion de limpieza y memoria.
// TODO establecer variables de entorno propias en nuestra shell

/**
 * @brief Initializes the internal environment linked list from the 'envp' array
 * This function iterates through the NULL-terminated 'envp' array provided
 * by the parent process. For each valid environment variable (containing
 * an '='), it performs a deep copy the variable's key and value. It then create
 * a new node for the environment linked list and adds it to the end of the 
 * list. The function's core logic adheres to the principle of "deep copy" to
 * ensure that the internal environment list is fully independent of the original
 * 'envp' array. It dynamically allocates memory for the key and value of each
 * variable.
 * @param envp A NULL-terminated array of strings, where each string is an
 * environment variable in the format "KEY=value". This is the source of the
 * environment data.
 * @param environment A pointer to a pointer to the head of the 't_env' linked
 * list. This double pointer is used to modify the head of the list directly,
 * allowing the function to build the list from scrath.
 * @note The temporary 'key' and 'value' strings created by 'get_key' and
 * 'get_value' are immediately freed after 'ft_lstnew_mini' has made its own
 * internal copies. This prevents memory leaks and ensures that ownership
 * of the allocated memory properly transferred to the new list node.
 * @note The function correctly handles the case where the 'envp' array might
 * contain invalid entries.
 */
bool	get_environment(char *envp[], t_env **environment)
{
	t_env	*new_node;
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i])
	{
		if (ft_strchr(envp[i], '=') != NULL)
		{
			key = set_key(envp[i]);
			value = set_value(envp[i]);
			if (!key || !value)
			{
				if (key)
					free(key);
				if (value)
					free(value);
				return (false);
			}
			new_node = ft_lstnew_mini_env(key, value, envp[i]);
			if (!new_node)
				return (free(key), free(value), false);
			ft_addback_mini_env(environment, new_node);
			free(key);
			free(value);
		}
		i++;
	}
	return (true);
}

/**
 * @brief Main function of the minishell.
 * The main function initializes the minishell environment by parsing the
 * 'envp' array received from the parent process. It creates a dynamic,
 * linked list representation of the environment variables. It then
 * demonstrates a simple traversal of this list and, crucially, performs a 
 * full cleanup of the allocated memory befor exiting.
 * @param argc The number of command-line arguments. Unused in this case.
 * @param argv An array of string containing the command line arguments. Unused
 * in this case.
 * @param envp An array of strings representing the environment variables
 * inherited from the parent process. This is the source data for the
 * minishell's internal environment structure.
 * @return Returns 0 upon successful execution and cleanup.
 * @note This main function serves as a test case to ensure that the
 * environment handling functions('get_environment' and 'free_environment')
 * work correctly. It verifies that the linked list is correctly populated
 * and that all dynamically allocated memory is properly freed at the end.
 * The '(void)argc and (void)argv' casts are used to explicitly mark these
 * parameters as intentionally unused, avoiding compiler warnings.
 int	main(int argc, char *argv[], char *envp[])
 {
	(void)argc;
	(void)argv;
	t_env	*environment;
	
	environment = NULL;
	get_environment(envp, &environment);
	
	// t_env	*temp;
	// temp = environment;
	// while (temp)
	// {
		// 	printf("%s\n", temp->full_env);
		// 	temp = temp->next;
		// }
		
		free_environment(&environment);
		return (0);
	}
	
*/