/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:10:27 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/09/06 03:28:02 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parser.c
 * @brief Main function for parsing a command toke stream.
 */
#include "minishell.h"

/**
 * @brief 
 * 
 * @param block 
 * @param tokens 
 * @return true 
 * @return false 
 */
/* static bool	fill_word_node(t_command *node, t_token *tokens)
{
	t_token		*temp;
	size_t		i;

	temp = tokens;
	i = 0;
	while (temp && temp->type == WORD)
	{
		node->cmd_args[i] = ft_strdup(temp->value);
		if (!node->cmd_args[i])
			return (ft_free_array(node->cmd_args), false);
		temp = temp->next;
		i++;
	}
	return (true);
} */

/**
 * @brief 
 * 
 * @param node 
 * @param tokens 
 * @return t_command* 
 */
static void	add_args(t_command **node, t_token *tokens)
{
	t_arg	*temp;
	t_arg	*new_arg;

	(*node)->cmd_argc += 1;
	new_arg = ft_calloc(1, sizeof(t_arg));
	if (!new_arg)
		return ;
	new_arg->value = ft_strdup(tokens->value);
	new_arg->next = NULL;
	temp = (*node)->args;
	while (temp->next)
		temp = temp->next;
	temp->next = new_arg;
}

/**
 * @brief 
 * 
 * @param tokens 
 * @return t_command* 
 */
static t_command	*create_cmd(t_token *tokens)
{
	t_command	*node;

	node = NULL;
	node = ft_calloc(1, sizeof(t_command));
	if (!node)
		return (NULL);
	node->args = NULL;
	node->next = NULL;
	node->redirs = NULL;
	node->cmd_argc = 1;
	node->args = ft_calloc(1, sizeof(t_arg));
	if (!node->args)
		return (free(node), NULL);
	node->args->value = ft_strdup(tokens->value);
	if (!node->args->value)
		return (free(node->args), free(node), NULL);
	node->args->next = NULL;
	return (node);
}

/**
 * @brief 
 * 
 * @param tokens 
 * @return t_command* 
 */
t_command	*parse_command(t_token *tokens)
{
	t_command	*cmd_list;
	t_command	*current_cmd;
	t_redir		*redir_node;
	t_token		*temp;

	cmd_list = NULL;
	current_cmd = NULL;
	redir_node = NULL;
	if (!tokens || tokens->type != WORD)
		return (printf("Lo primero necesita ser un comando\n"), NULL);
	temp = tokens;
	while (temp)
	{
		if (temp->type == WORD)
		{
			if (!current_cmd)
				current_cmd = create_cmd(temp);
			else
				add_args(&current_cmd, temp);
			temp = temp->next;
			if (!temp)
			{
				lstaddback_cmd(&cmd_list, current_cmd);
				break ;
			}
			if (temp->type != WORD && temp->type != PIPE)
			{
			if (temp->next == NULL || temp->next->type != WORD)
				return (printf("se necesita un target"), free(current_cmd), NULL);
			redir_node = create_redir(temp);
			add_redir(&current_cmd, redir_node);
			temp = temp->next->next;
			}
		}
		if (!temp)
		{
		lstaddback_cmd(&cmd_list, current_cmd);
			break ;
		}
/* 		if (temp->type == PIPE) 
		{
			break ;
		}
 */
	}
	return (cmd_list);
}
