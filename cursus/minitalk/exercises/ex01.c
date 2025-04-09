/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:34:18 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/09 14:10:49 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/*
Objetivo: Escribir un programa que establezca un manejador para SIGINT (Ctrl+C) usando signal y que imprima un mensaje al recibir la señal.
*/

/*
Esta función se ejecuta cuando el proceso recibe la señal SIGINT (por ejemplo, al presionar Ctrl+C).
La función simplemente muestra un mensaje por terminal.
*/
void	handler_function(int i)
{
	(void) i;
	printf("\nInterruption Detect!!\n");
}

/*
Llamamos a la función signal, y asociamos la funcion handler_function a la señal SIGINT 'Ctrl + C'
Si devuelve algun tipo de Error, lo imprime sino ejecuta la función manejadora.
*/

int main(void)
{
	if (signal(SIGINT, handler_function) == SIG_ERR)
		printf("Error\n");
	while (1)
		pause();
	return (0);
}
