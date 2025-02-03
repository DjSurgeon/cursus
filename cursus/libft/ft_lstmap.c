/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:04:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/03 15:29:17 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: apply the function over the list, and create a new list
**	parameters: pointer a node, the function to apply and the delete function
**	return: the new list
*/

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
			ft_lstclear(&result_node, del);
			return (NULL);
		}
		ft_lstadd_back(&result_list, result_node);
		lst = lst->next;
	}
	return (result_list);
}
