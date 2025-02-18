/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:07:26 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/18 12:00:03 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
**	description: check the char after the format parameter and print the
**	string accoprding the format and arguments
**	parameters: the list of paramters and the string
**	return: the numbers of chars printed
*/

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
		count += ft_counthexalo(va_arg(parameters, unsigned int));
	if (*str == 'X')
		count += ft_counthexaup(va_arg(parameters, unsigned int));
	if (*str == 'p')
		count += ft_countpointer(va_arg(parameters, uintptr_t));
	return (count);
}
/*
**	description: check in the string if the format character exits
**	paramters: the list of parameters, the string
**	return: the numbers of chars printed
*/

static int	check_str(va_list parameters, const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '\0')
			return (-1);
		if (*str == '%' && ft_strchr("csiduxXp%", *(str + 1)))
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
/*
**	description: write the output of a format string that specifies
**	in the arguments
**	parameters: a const string, an unlimited number of parameters
**	return: the numbers of chars printed
*/

int	ft_printf(char const *str, ...)
{
	va_list	parameters;
	int		count;

	count = 0;
	if (!str)
		return (0);
	va_start(parameters, str);
	count = check_str(parameters, str);
	va_end(parameters);
	return (count);
}
