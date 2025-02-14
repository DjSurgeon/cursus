/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:36:20 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/14 01:38:39 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	hexadecimal_lower(long n)
{
	char	hexa[16] = "0123456789abcdef";
	char	number;

	if (n == -2147483648)
		write(1, "-80000000", 9);
	else if (n < 0)
	{
		n =  n * -1;
		write(1, "-", 1);
		if (n >= 16)
			hexadecimal_lower(n / 16);
		number = (n % 16);
		number = hexa[number];
		write (1, &number, 1);
	}
	else
	{
		if (n >= 16)
			hexadecimal_lower(n / 16);
		number = (n % 16);
		number = hexa[number];
		write (1, &number, 1);
	}
}
// ****************************
int	check_chars(va_list parameters, char str)
{
	int		count;
	char	c;
	char	*string;

	count = 0;
	if (str == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
	else if (str == 'c')
	{
		c = va_arg(parameters, int);
		ft_putchar_fd(c, 1);
		count++;
	}
	else if (str == 's')
	{
		string = va_arg(parameters, char *);
		ft_putstr_fd(string, 1);
		count = ft_strlen(string);
	}
	return (count);
}

int	check_ints(va_list parameters, char str)
{
	int				count;
	int				number;
	unsigned int	unumber;

	count = 0;
	if (str == 'd' || str == 'u' )
	{
		number = va_arg(parameters, int);
		ft_putnbr_fd(number, 1);
		count += ft_longlen(number);
	}
	else if (str == 'u')
	{
		unumber = va_arg(parameters, unsigned int);
		ft_putnbr_unsig_fd(number, 1);
		count += ft_longlen(unumber);
	}
	return (count);
}
int	check_hexas(va_list parameters, char str)
{
	int		count;
	long	number;
	
	count = 0;
	if(str == 'x')
	{
		number = va_arg(parameters, long);
		hexadecimal_lower(number);
		
	}
}