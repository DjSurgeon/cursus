/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:53:28 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/13 16:07:36 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_int_nbr(int n)
{
	char	unit;
	int		digits;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	digits = len_int_nbr(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		write_int_nbr(n / 10);
	unit = (n % 10) + '0';
	write (1, &unit, 1);
	return (digits);
}
