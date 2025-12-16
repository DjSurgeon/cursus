/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:52:39 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/13 16:19:51 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_str(char *str)
{
	int		count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (*str)
	{
		count += write(1, str, 1);
		str ++;
	}
	return (count);
}
