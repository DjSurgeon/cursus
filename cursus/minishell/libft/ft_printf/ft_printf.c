/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:58:45 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/17 17:17:55 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
Send the current variadic arg to the writer functions 
according to the format. Exception for "%%"). 
Bring back the count
Unsigned long type and unsigned int cast in hexadecimal format
were used to prevent unwanted behaviors when we got
ULONG_MAX/MIN & LONG_MAX/MIN. 
*/
static int	v_arg_format(va_list v_args, char const *c)
{
	if (*c == '%')
		return (write(1, "%", 1));
	else if (*c == 'c')
		return (write_char(va_arg(v_args, int)));
	else if (*c == 's')
		return (write_str(va_arg(v_args, char *)));
	else if (*c == 'p')
		return (write_ptr(va_arg(v_args, void *)));
	else if (*c == 'd' || *c == 'i')
		return (write_int_nbr(va_arg(v_args, int)));
	else if (*c == 'u')
		return (write_uns_int_nbr(va_arg(v_args, unsigned int)));
	else if (*c == 'x')
		return (write_hex((unsigned int) va_arg(v_args, unsigned long), 0));
	else if (*c == 'X')
		return (write_hex((unsigned int) va_arg(v_args, unsigned long), 1));
	return (0);
}

/* 
The next function navigates through the fixed arg as a string
printing each character keeping it's count.
Whenever we find the format signal(%), we call the function that
takes care of each suported format.
IMPORTANT: Added extra control for "%" scenario.
*/
static int	navigate_fix_arg(va_list v_args, char const *fix_arg)
{
	int		count;

	count = 0;
	while (*fix_arg != '\0')
	{
		if (*fix_arg == '%' && *(fix_arg + 1) == '\0')
			return (-1);
		if (*fix_arg == '%' && ft_strchr("cspdiuxX%", *(fix_arg + 1)))
		{
			fix_arg ++;
			count += v_arg_format(v_args, fix_arg);
		}
		else
			count += write_char((char) *fix_arg);
		fix_arg ++;
	}
	return (count);
}

/* 
1) Check if there's the mandatory fixed arg.
2) Iniziate the variadic args list.
3) Get the whole thing to work as we ask for the print count back.
4) Close the v_arg list and take our total count.
IMPORTANT: Added extra control for empty string!!
 */
int	ft_printf(char const *fix_arg, ...)
{
	int			count;
	va_list		v_args;

	if (!fix_arg || fix_arg[0] == '\0')
		return (0);
	va_start(v_args, fix_arg);
	count = navigate_fix_arg(v_args, fix_arg);
	va_end(v_args);
	return (count);
}
