/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:56:21 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/06 10:50:08 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	variables estaticas
**	en una variable normal, cada llamada la variable i se inicializa en i = 1
**	por lo tanto siempre en la llamada el resultado es 2
**	en la variable estatica, el valor se mantiene entre llamadas
**	por lo tanto el valor va creciendo
*/

#include <unistd.h>
#include <stdio.h>

void	print_var(void)
{
	int			i = 1;
	static int	j = 1;

	i = i + 1;
	j = j + 1;
	printf("%i\n", i);
	printf("%i\n", j);
	printf("=====\n");
}
int main(void)
{
	print_var();
	print_var();
	print_var();
	
	return (0);
}