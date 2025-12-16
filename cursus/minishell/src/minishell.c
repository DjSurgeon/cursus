/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:11:50 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/08/30 08:48:44 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/// @brief Main function containing our Read Evaluate Print(Execute) Loop
/// @param envp data is saved as a linked list in 'environment'
int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_env	*environment;
	//PIPES_TEST:
	char	**pipe_args;
	char	*trimmed;
	int		i;
	int 	num_blocks;
	int		exit_pipes;
	//TESTS_REDIRECCION:
	int		in;
	int		out;
	//LEXER:
	//t_token	*tokenlist;

	(void)argc;
	(void)argv;
	environment = NULL;
	if (!get_environment(envp, &environment))
		return (free_environment(&environment), perror("envp copy failed"), 1);
	while (1)
	{
		in = -1;
		out = -1;
		exit_pipes = 0;
		input = readline("$> ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
		{
			add_history(input);

			// tokenlist = tokenizer(input);
			// print_list(tokenlist);
			// pipe_args = tokenlist_to_arr(tokenlist);
			// print_array(pipe_args);

			// parseo de pipes:
			pipe_args = ft_split((const char*)input, '|');
			print_array(pipe_args);
			i = 0;
			while (pipe_args[i])
			{
				trimmed = ft_strtrim(pipe_args[i], " \t\n<>");
				free(pipe_args[i]);
				pipe_args[i] = trimmed;
				i++;
			}
			num_blocks = 0;
			while (pipe_args[num_blocks])// número de bloques de comandos
				num_blocks++;
			if (in == -1)//detectamos si estamos usando FDs especiales (si hemos incorporado redirecciones, etc.)
				in = 0;//si no, usamos std in and out
			if (out == -1)
				out = 1;
			exit_pipes = pipes(pipe_args, num_blocks, &environment, in, out);//Esto debería centralizar todo, creo. Si sólo hay un comando, usará un comando
			printf("exit status: %d\n", exit_pipes);
			ft_close_two(in, out);
			ft_free_array(pipe_args);
			//free_tokens(&tokenlist);
		}
		free(input);
	}
	free_environment(&environment);
	rl_clear_history();
	return (0);
}
