/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:33:56 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/22 13:45:35 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		lst_count;

	if (!lst)
		return (0);
	temp = lst;
	lst_count = 0;
	while (temp)
	{
		temp = temp -> next;
		lst_count++;
	}
	return (lst_count);
}
