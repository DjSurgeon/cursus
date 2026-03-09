/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:04:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/03 23:39:32 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the content 
 * of each node. Creates a new list resulting of the successive applications of 
 * the function 'f'. The 'del' function is used to delete the content of a node 
 * if needed.
 *
 * @param lst A pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a node.
 * @return The new list. NULL if the allocation fails.
 */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_node;
	t_list	*result_list;

	result_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		result_node = ft_lstnew(f(lst->content));
		if (!result_node)
		{
			ft_lstclear(&result_list, del);
			return (NULL);
		}
		ft_lstadd_back(&result_list, result_node);
		lst = lst->next;
	}
	return (result_list);
}
