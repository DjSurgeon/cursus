/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:48:52 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/07 13:09:46 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_list;
	t_list	*result_element;

	if (!lst || !f || !del)
		return (NULL);
	result_list = NULL;
	while (lst)
	{
		result_element = ft_lstnew(f(lst -> content));
		if (!result_element)
		{
			ft_lstclear(&result_list, del);
			return (NULL);
		}
		ft_lstadd_back(&result_list, result_element);
		lst = lst->next;
	}
	return (result_list);
}
