/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:37:30 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/01 17:38:00 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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