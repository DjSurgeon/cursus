/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilnumbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:50:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/17 01:42:00 by sergio-jime      ###   ########.fr       */
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

int	ft_counthexalo(unsigned long long n)
{
	char	hexa[16];
	char	number;
	int		count;

	count = 0;
	ft_memcpy(hexa, "0123456789abcdef", 16);
	if (n == 0)
		count += write(1, "0", 1);
	if (n >= 16)
		count += ft_counthexalo(n / 16);
	number = hexa[n % 16];
	count += write (1, &number, 1);
	return (count);
}

int	ft_counthexaup(unsigned long long n)
{
	char	hexa[16];
	char	number;
	int		count;

	count = 0;
	ft_memcpy(hexa, "0123456789ABCDEF", 16);
	if (n == 0)
		count += write(1, "-", 1);
	if (n >= 16)
		count += ft_counthexaup(n / 16);
	number = hexa[n % 16];
	count += write (1, &number, 1);
	return (count);
}

int	ft_countpointer(unsigned long long n)
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
