/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:55:14 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/15 17:04:20 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_hex(unsigned long hex, int upper_flag)
{
	char	*hexadec;
	int		digits;

	if (hex == 0)
		return (write(1, "0", 1));
	if (upper_flag == 0)
		hexadec = "0123456789abcdef";
	if (upper_flag == 1)
		hexadec = "0123456789ABCDEF";
	if (hex > 15)
		write_hex(hex / 16, upper_flag);
	write(1, &hexadec[hex % 16], 1);
	digits = 0;
	while (hex)
	{
		hex /= 16;
		digits++;
	}
	return (digits);
}
