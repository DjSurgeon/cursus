/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_countstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:01:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/16 13:52:45 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	description: count a number of digits and write it
**	parameters: a int number
**	return: the numbers of digits printed
*/

int	ft_ps_countstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	while (ft_isdigit(s[i]))
	{
		i++;
		count++;
	}
	return (count);
}
