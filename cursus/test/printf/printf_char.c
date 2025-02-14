/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:39:22 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/14 01:36:25 by sergio-jime      ###   ########.fr       */
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
void	ft_putnbr_unsigned(unsigned int n)
{
	char	number;

	if (n == 0)
		write(1, "0", 1);
	else
	{
		if (n >= 10)
			ft_putnbr_unsigned(n / 10);
		number = (n % 10) + '0';
		write(1, &number, 1);
	}
}
void	hexadecimal_upper(long n)
{
	char	hexa[16] = "0123456789ABCDEF";
	char	number;

	if (n == -2147483648)
		write(1, "-80000000", 9);
	else if (n < 0)
	{
		n =  n * -1;
		write(1, "-", 1);
		if (n >= 16)
			hexadecimal_upper(n / 16);
		number = (n % 16);
		number = hexa[number];
		write (1, &number, 1);
	}
	else
	{
		if (n >= 16)
			hexadecimal_upper(n / 16);
		number = (n % 16);
		number = hexa[number];
		write (1, &number, 1);
	}
}
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

char	*ft_itoa_long(long n)
{
	size_t	len;
	char	*result;
	int		negative;

	len = intlen(n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	negative = 1;
	if (n < 0)
	{
		n = -n;
		negative = 0;
	}
	aux_itoa(result, n);
	if (negative != 1)
	{
		result[len - 1] = '-';
	}
	reverse_string(result, len);
	result[len] = '\0';
	return (result);
}
/**********************************************/
int	ft_printf(char const *str, ...)
{
	va_list	parameters;
	int		count;
	char	*aux;
	
	count = 0;
	*aux = *str;
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
				count += intlen(number) - 1;
				ft_putnbr_unsigned(number);
			}
/* 			if (*str == 'X' )
			{
				int	number	= va_arg(parameters, int);
				hexadecimal_upper(number); // <- necesito devolver un char y contarlo
				// count += ft_strlen(ft_itoa(number)); otro contdor este no vale
			}
			if (*str == 'x')
			{
				int number = va_arg(parameters, int); 
				hexadecimal_lower(number); // mismo problema que en el upper, mal contador
			}
			if (*str == 'p')
			{
				char	*result_pointer;
				void 	*pointer = va_arg(parameters, void*);
				write(1, "0x", 2);
				result_pointer = ft_itoa_long((long) pointer); //imprime bien ahora hay que contarlo igual
				// count += ft_strlen(result_pointer);
			} */
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
		count++;
	}	
	va_end(parameters);
	// str = '\0';
	// count = ft_strlen(aux);
	return (count);
}

int	main(void)
{
	int	count1 = 0;
	int	count2 = 0;

	char *string = "hola";
	void *pointer = &string;
	
	count1 = ft_printf("%i %sc %% %d %c\n<- unsigned\n",+1234-5,  "hola", -12, 'c');
	ft_printf("\n\n^^ ft_printf == printf vv\n\n");
	count2 = printf("%i %sc %% %d %c\n<- unsigned\n",+1234-5,  "hola", -12, 'c');

	ft_printf("\n\nRetorno printf: \n");
	ft_printf("ft_printf: %i\n", count1);
	printf("printf: %i\n", count2);
	return (0);
}