/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:25:00 by serjimen          #+#    #+#             */
/*   Updated: 2025/08/22 18:15:46 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_lstsize_mini(t_env *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

/**
 * OJO!: He cambiado la asignación a través de un ft_strdup(), porque si no
 depende de lo que haya en envlist ya que sólo asignamos puntero al contenido del nodo.
 Con strdup nos aseguramos de que tenemos un array independiente sobre el que luego
 podemos hacer free
 */
char	**envlist_to_arr(t_env **envlist)
{
	int		count;
	char	**envarr;
	t_env	*temp;
	int		i;

	count = ft_lstsize_mini(*envlist);
	envarr = ft_calloc(count + 1, sizeof(char *));
	if (!envarr)
		return (NULL);
	temp = *envlist;
	i = 0;
	while (temp)
	{
		envarr[i] = ft_strdup(temp->full_env);
		temp = temp->next;
		i++;
	}
	envarr[i] = NULL;
	return (envarr);
}
