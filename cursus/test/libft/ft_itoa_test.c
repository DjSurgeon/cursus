/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:15:02 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/29 11:50:32 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
// #include "libft.h"

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
char    *ft_itoa(int n)
{
	size_t	len; // longitud de la cadena que vamos a imprimir
	char	*result; // cadena resultante, la vamos modificando
	int		negative; // variable para gestionar el signo
	long	num; // vamos a traabajar con long para el caso de INT_MIN

	num = n;
	len = intlen(num); // calculamos la longitud del int
	result = malloc(len + 1); // reservamos la memoria de la longitud del int + el caracter '\0'
	if (result == NULL)
		return (NULL);
	negative = 1; // si negative es 1 es numero positivo
	if (n < 0)
	{
		// result[0] = '-';
		num = -num; // ¿¿¿¿¿gestionar mx int???
		negative = 0; // si negative es 0 es numero negativo
	}
	aux_itoa(result, num);
	if (negative != 1)
	{
		result[len-1] = '-'; // si es negativo colocamos el signo
	}
	reverse_string(result, len);
	result[len] = '\0'; // cerramos la cadena con el '\0'
	return (result);
}

int main(void)
{
    char *str = ft_itoa(0);
    printf("%s\n", str);
    free(str); // Liberamos la memoria asignada.
    return 0;
}