/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:29:49 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/24 14:01:36 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen (int n) // encapsulamos la funcion con static funcion para contar cadenas
{
	size_t count;

	count = 0;
	if (n <= 0)	// si es negativo o cero
	{
		count++; // contamos un digito el signo o el 0
	}
	while (n != 0)
	{
		n = n / 10; // vamos eliminando el ultimo digito
		count++;	// aumentamos el contador
	}
	return count; // retornamos el numero
}
static void	reverse_string(char *s, size_t len) // funcion para revertir cadenas
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
			s[end] =  swap;
			start++;
			end--;
		}
	}
}
static char*	aux_itoa(char *s, int n)
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
char    *ft_itoa(int n)
{
	size_t	len; // longitud de la cadena que vamos a imprimir
	char	*result; // cadena resultante, la vamos modificando
	int		negative; // variable para gestionar el signo

	len = intlen(n); // calculamos la longitud del int
	result = malloc(len + 1); // reservamos la memoria de la longitud del int + el caracter '\0'
	if (result == NULL)
		return (NULL);
	negative = 1; // si negative es 1 es numero positivo
	if (n < 0)
	{
		n = -n;
		negative = 0; // si negative es 0 es numero negativo
	}
	aux_itoa(result, n);
	if (negative != 1)
	{
		result[len-1] = '-'; // si es negativo colocamos el signo
	}
	reverse_string(result, len);
	result[len + 1] = '\0'; // cerramos la cadena con el '\0'
	return (result);
}
