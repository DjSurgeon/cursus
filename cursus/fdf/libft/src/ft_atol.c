/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:38:41 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/03 22:56:33 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * @brief convert a string to long (ascii to long)
 * @param str a pointer to string
 * @return a long
**/

#include "libft.h"

long	ft_atol(const char *str)
{
	size_t	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
