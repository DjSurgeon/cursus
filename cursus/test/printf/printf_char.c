/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:39:22 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/11 17:38:45 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_printf(char const *str, ...)
{
	va_list parameters;
	
	va_start(parameters, str);

	while (*str)
	{	
		if (*str == '%')
		{
			str++;
			if (*str == '%')
			{
				ft_putchar('%');
			}
			if (*str == 'c')
			{
				char c = va_arg(parameters, int);
				ft_putchar(c);
			}
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
	}	
	va_end(parameters);
	
	return (0);
}

int	main(void)
{
	int c = 77;
	ft_printf("%c ho %c la %% ho %c a",c , 'x', 'k');
	
	return (0);
}