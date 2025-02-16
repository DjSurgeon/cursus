/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:07:26 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/17 00:01:19 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_module(va_list parameters, const char *str)
{
	int	count;

	count = 0;
	if (*str == '%')
		count += ft_countchar('%');
	if (*str == 'c')
		count += ft_countchar(va_arg(parameters, int));
	if (*str == 's')
		count += ft_countstr(va_arg(parameters, char *));
	if (*str == 'i' || *str == 'd')
		count += ft_countint(va_arg(parameters, int));
	if (*str == 'u')
		count += ft_countunsig(va_arg(parameters, unsigned int));
	if (*str == 'x')
		count += ft_counthexalo(va_arg(parameters, long));
	if (*str == 'X')
		count += ft_counthexaup(va_arg(parameters, long));
	if (*str == 'p')
		count += ft_countpointer((long)va_arg(parameters, void *));
	return (count);
}

static int	check_str(va_list parameters, const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += check_module(parameters, str);
		}
		else
			count += ft_countchar(*str);
		str++;
	}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	parameters;
	int		count;

	count = 0;
	va_start(parameters, str);
	count = check_str(parameters, str);
	va_end(parameters);
	return (count);
}
