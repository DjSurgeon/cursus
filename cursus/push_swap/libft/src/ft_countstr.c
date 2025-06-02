/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:39:31 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/02 11:39:53 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	description: write a string and count it
**	parameters: a string
**	return: the numbers of chars printed
*/

int	ft_countstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}
