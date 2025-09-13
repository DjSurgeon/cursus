/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:28:00 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/02 11:39:59 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
