/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:56:40 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/13 14:53:02 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Algoritmo para pasar de decimal a hexadecimal
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	hexadecimal_upper(int n)
{
	char	hexa[16] = "0123456789ABCDEF";
	char	number;

	if (n == -2147483648)
		write(1, "-80000000", 9);
	else if (n < 0)
	{
		n =  n * -1;
		write(1, "-", 1);
		if (n >= 16)
			hexadecimal_upper(n / 16);
		number = (n % 16);
		number = hexa[number];
		write (1, &number, 1);
	}
	else
	{
		if (n >= 16)
			hexadecimal_upper(n / 16);
		number = (n % 16);
		number = hexa[number];
		write (1, &number, 1);
	}
}

char	*hexadecimal_lower(long n)
{
	char	hexa[16] = "0123456789abcdef";
	char	*hexa_number;
	int		number;

	if (n == -2147483648)
	{
		hexa_number = "-80000000";
		return (*hexa_number);
	}	
	else if (n < 0)
	{
		n =  n * -1;
		hexa_number[0] = '-';
		if (n >= 16)
			hexadecimal_lower(n / 16);
		number = (n % 16);
		hexa_number = &hexa[number];
		return (*hexa_number);
	}
	else
	{
		if (n >= 16)
			hexadecimal_lower(n / 16);
		number = (n % 16);
		hexa_number = &hexa[number];
		return (*hexa_number);
	}
}

int main(void)
{
	char	*s;

	s = hexadecimal_lower(0);
	printf("%s", s);
	
	return (0);
}