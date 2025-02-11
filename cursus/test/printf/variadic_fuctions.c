/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_fuctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:23:04 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/11 16:32:26 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

/*
**	Funciones variadicas, son funciones que pueden recibir un numero ilimitado de argumentos
**	para declara un numero indeterminado de argumentos se utiliza las elipsis (...)
**	la elipsis debe estar declarada como el ultimo argumento de la función
**	para trabajar con ello necesitamos utilizar algunas macros, las cuales trabajaran
**	como funciones. Para trabajar con estas macros lo primero sera definir una lista
**		va_list	list;
**	esta lista podre almacenar una cantidad ilimitada de argumentos de todo tipo
**		va_start(list, parameter)
**
*/


/*
**	Crearemos una función que nos de la media de los numeros utilizados
**	
*/
double	average(int numbers, ...) // Los parametros seran una cantidad indeterminada de doubles
{
	double	result;
	double	sum;
	int		i;
	va_list	numbers_list;				// Creacion de la lista donde almacenaremos los ints
	
	sum = 0.0f;
	i = 0;
	result = 0.0f;
	va_start(numbers_list, numbers);	// Inicializamos la lista.

	while (i < numbers)
	{
		// printf("-> %f\n", va_arg(numbers_list, double));
		sum += va_arg(numbers_list, double);	// iteramos sobre los valores de la lista
		printf("%f\n", sum);
		i++;
	}
	result = sum / numbers;
	va_end(numbers_list);				// cerramos la lista
	
	return (result);
}

int	main (void)
{
	double	media;
	
	media = average(5, 5.0, 5.0, 10.0, 10.0, 7.0);
	printf("%f", media);
		
	return (0);
}