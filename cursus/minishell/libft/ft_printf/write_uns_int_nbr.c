/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uns_int_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:54:22 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/15 17:06:08 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_uns_int_nbr(unsigned int uns_nbr)
{
	char	unit;
	int		digits;

	if (uns_nbr == 0)
		return (write(1, "0", 1));
	if (uns_nbr > 9)
		write_uns_int_nbr(uns_nbr / 10);
	unit = (uns_nbr % 10) + '0';
	write (1, &unit, 1);
	digits = 0;
	while (uns_nbr)
	{
		uns_nbr /= 10;
		digits++;
	}
	return (digits);
}
