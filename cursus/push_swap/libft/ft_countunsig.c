/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countunsig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:25:32 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/02 10:25:58 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
