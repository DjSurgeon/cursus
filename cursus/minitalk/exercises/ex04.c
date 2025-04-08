/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:53:28 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/08 16:26:35 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Un char ocupa 1 byte → 8 bits. Cada bit puede ser 0 o 1.

Decimal:		65 (A)
Binario:		01000001
Índices:		76543210 (bit más significativo a menos)

*/

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int i)
{
	char	c;
	if(i >= 0 && i <= 9)
		c = i + '0';
	write(1, &c, 1);
}

void	print_bits(char c)
{
	int	i;
	int bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		ft_putnbr(bit);
		i--;
	}
}

int main(void)
{
	char c;

	c = 'z';
	ft_putchar(c);
	write(1, "\n", 1);
	write(1, "76543210 index\n", 15);
	print_bits(c);
	return (0);
}
