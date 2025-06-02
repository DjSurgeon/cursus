/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:24:53 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/02 10:25:04 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
