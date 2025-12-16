/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:47:33 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/09/05 01:53:41 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "structs.h"

//MINISHELL UTILS:
void		ft_free_array(char **array);

//ENVIRONMENT:
bool		get_environment(char *envp[], t_env **environment);
void		free_environment(t_env **env);
char		*set_key(char *str);
char		*set_value(char *str);
t_env		*ft_lstnew_mini_env(char *key, char *value, char *full);
void		ft_addback_mini_env(t_env **head, t_env *new_node);
char		*get_value_by_key(t_env *env_list, const char *key);
char		*get_full_env(t_env *env_list, const char *key);

//EXECUTOR_UTILS:
void		cmd_not_found(char *cmd, char **args);
char		**ft_potential_paths(char **envp);
char		*ft_build_full_path(char *command, char **envp);
char		*ft_check_path(char *command, char **envp);
char		**envlist_to_arr(t_env **envlist);
char		**tokenlist_to_arr(t_token *tokenlist);

//EXECUTOR:
void		execute_command(char *cmd_str, t_env **envp);
void		command_in(char *command, t_env **environment);

//PIPES:
int			pipes(char **args, int blocks, t_env **env_list, int in, int out);
void		safe_close(int fd);
void		ft_close_two(int fd1, int fd2);
void		ft_close_three(int fd1, int fd2, int fd3);
int			ft_wait_and_exit(pid_t last_pid);

//INPUT_OUTPUT:
int			get_inputfile_fd(char *infile);
int			get_outputfile_fd(char *outfile);
int			get_append_fd(char *outfile);
int			get_heredoc_fd(char *limiter);

//LEXER
t_token		*tokenizer(char *str);
t_token		*lstnew_token(char *value, t_token_type type);
void		lstaddback_token(t_token **head, t_token *new_node);
void		free_tokens(t_token **tokens);

//LEXER_TEST:
void		print_list(t_token *list);
void		print_array(char **array);

//PARSER
t_command	*parse_command(t_token *tokens);
size_t		lstsize_token_word(t_token *lst);
t_redir		*create_redir(t_token *tokens);
void		add_redir(t_command **cmd_node, t_redir *new_redir);
void		lstaddback_cmd(t_command **head, t_command *new_node);
void	*ft_realloc(void *ptr, size_t size, size_t oldsize);

//PARSER TEST
void		free_commands(t_command **commands);
void		print_commands(t_command *commands);

#endif