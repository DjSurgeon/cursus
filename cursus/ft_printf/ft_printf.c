/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:07:26 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/14 01:25:20 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(char const *str, ...)
{
	va_list	parameters;
	int		count;

	count = 0;
	va_start(parameters, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += check_chars(parameters, *str);
			count += check_ints(parameters, *str);
			count += check_hexas(parameters, *str);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(parameters);
	return (count);
}
