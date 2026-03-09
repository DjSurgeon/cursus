/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:30:33 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/03 23:39:06 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Takes as a parameter a node and frees the memory of the node’s 
 * content using the function 'del' given as a parameter and free the node.
 *
 * The memory of 'next' must not be freed.
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}
