/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:39:22 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/12 12:32:06 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
static size_t	intlen(long n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
	{
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	reverse_string(char *s, size_t len)
{
	size_t	start;
	size_t	end;
	char	swap;

	start = 0;
	end = len - 1;
	{
		while (start < end)
		{
			swap = s[start];
			s[start] = s[end];
			s[end] = swap;
			start++;
			end--;
		}
	}
}

static char	*aux_itoa(char *s, long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*result;
	int		negative;
	long	num;

	num = n;
	len = intlen(num);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	negative = 1;
	if (n < 0)
	{
		num = -num;
		negative = 0;
	}
	aux_itoa(result, num);
	if (negative != 1)
	{
		result[len - 1] = '-';
	}
	reverse_string(result, len);
	result[len] = '\0';
	return (result);
}
void	ft_putnbr_fd(int n, int fd)
{
	char	number;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		number = (n % 10) + '0';
		write(fd, &number, 1);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		number = (n % 10) + '0';
		write(fd, &number, 1);
	}
}
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
			if (*str == '%')					// imprime el simbolo de porcentaje
			{
				ft_putchar('%');
			}
			if (*str == 'c')					// imprime carácteres
			{
				char	c = va_arg(parameters, int);
				ft_putchar(c);
			}
			if (*str == 's')					// imprime strings
			{
				char	*str = va_arg(parameters, char *);
				ft_putstr(str);
				count += ft_strlen(str) - 1;
			}
			if (*str == 'd' || *str == 'i')		// imprime ints
			{
				int	number = va_arg(parameters, int);
				count += intlen(number) - 1;
				ft_putnbr_fd(number, 1);
			}
			if (*str == 'u')					// imprime unsigned int
			{
				unsigned int	number = va_arg(parameters, unsigned int);
				// TODO itoa de unsigned ints o putnbr de unsigned
			}
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
		count++;
	}	
	va_end(parameters);
	str = '\0';
	return (count);
}

int	main(void)
{
	int	count1 = 0;
	int	count2 = 0;
	
	count1 = ft_printf("%i %sc %% %d %c\n",+1234-5,  "hola", -12, 'c');
	count2 = printf("%i %sc %% %d %c\n",+1234-5,  "hola", -12, 'c');
	// count = ft_printf("h o%%la%c\n", 'z');
	ft_printf("%i\n", count1);
	printf("%i\n", count2);
	return (0);
}