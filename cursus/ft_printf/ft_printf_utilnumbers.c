/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilnumbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:50:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/18 10:25:54 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
**	description: count a number of digits and write it
**	parameters: a int number
**	return: the numbers of digits printed
*/

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
/*
**	description: count the number of digits only in positive
**	numbers, unsigned
**	parameters: an unsigned int number
**	return: the number of digits printed
*/

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
/*
**	description: convert a decimal number in format hexadecimal
**	in lowercase format
**	parameters: an unsigned long long number
**	return: the number of digits printed
*/

int	ft_counthexalo(unsigned long long n)
{
	char	hexa[16];
	char	number;
	int		count;

	count = 0;
	ft_memcpy(hexa, "0123456789abcdef", 16);
	if (n >= 16)
		count += ft_counthexalo(n / 16);
	number = hexa[n % 16];
	count += write (1, &number, 1);
	return (count);
}
/*
**	description: convert a decimal number in format hexadecimal
**	in uppercase format
**	parameters: an unsigned long long number
**	return: the number of digits printed
*/

int	ft_counthexaup(unsigned long long n)
{
	char	hexa[16];
	char	number;
	int		count;

	count = 0;
	ft_memcpy(hexa, "0123456789ABCDEF", 16);
	if (n >= 16)
		count += ft_counthexaup(n / 16);
	number = hexa[n % 16];
	count += write (1, &number, 1);
	return (count);
}
/*
**	description: convert a pointer in format hexadecimal
**	in lowercase format
**	parameters: an unsigned long long number
**	return: the number of digits printed
*/

int	ft_countpointer(uintptr_t n)
{
	int		count;

	count = 0;
	if ((void *)n == NULL)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_counthexalo(n);
	return (count);
}
