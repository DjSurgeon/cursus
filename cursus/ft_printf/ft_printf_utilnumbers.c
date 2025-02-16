/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilnumbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:50:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/17 00:04:07 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countint(int n)
{
	char	number;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		count += ft_countint(n / 10);
	number = (n % 10) + '0';
	count += write(1, &number, 1);
	return (count);
}

int	ft_countunsig(unsigned int n)
{
	char	number;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_countint(n / 10);
	number = (n % 10) + '0';
	count += write(1, &number, 1);
	return (count);
}

int	ft_counthexalo(long n)
{
	char	hexa[16];
	char	number;
	int		count;

	hexa = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 16)
		count += ft_counthexalo(n / 16);
	number = hexa[n % 16];
	count += write (1, &number, 1);
	return (count);
}

int	ft_counthexaup(long n)
{
	char	hexa[16];
	char	number;
	int		count;

	hexa = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 16)
		count += ft_counthexaup(n / 16);
	number = hexa[n % 16];
	count += write (1, &number, 1);
	return (count);
}

int	ft_countpointer(long n)
{
	int		count;

	count = 0;
	if ((void *)n == NULL)
	{
		count += write(1, ("(nil)"), 5);
		return (count);
	}
	count += write(1, "0x", 2);
	if (n >= 16)
		count += ft_counthexalo(n);
	return (count);
}
