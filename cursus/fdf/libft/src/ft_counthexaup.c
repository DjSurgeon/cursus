/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counthexaup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:27:07 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/02 11:40:09 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
