/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:19:48 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/09/04 14:30:30 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parser_redir.c
 * @brief 
 */
#include "minishell.h"

void	lstaddback_cmd(t_command **head, t_command *new_node)
{
	t_command	*current;

	if (!head || !new_node)
		return ;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	add_redir(t_command **cmd_node, t_redir *new_redir)
{
	t_redir	*current;

	if (!*cmd_node || !new_redir)
		return ;
	if (!(*cmd_node)->redirs)
	{
		(*cmd_node)->redirs = new_redir;
		return ;
	}
	current = (*cmd_node)->redirs;
	while (current->next)
		current = current->next;
	current->next = new_redir;
}

t_redir	*create_redir(t_token *tokens)
{
	t_token		*temp;
	t_redir		*redir;
	
	redir = NULL;
	temp = tokens;
	redir = ft_calloc(1, sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = temp->type;
	redir->next = NULL;
	redir->file = ft_strdup(temp->next->value);
	return (redir);
}
