/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilchars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:48:12 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/18 12:05:16 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
**	description: write the char and count it
**	parameters: a char
**	return: the number of char printed
*/

int	ft_countchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}
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
