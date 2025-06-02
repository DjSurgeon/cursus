/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:15:21 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/17 00:23:38 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: lowercase the char
**	parameter: char c in ascii
**	return: the char in lowercase
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
		return (c);
	}
	return (c);
}
