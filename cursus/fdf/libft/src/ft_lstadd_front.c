/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:32:03 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/01 16:04:19 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: add the new node to the front of the list
**	parameters: pointer to the memory direction of the first node, the new node
**	return: nothing
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
