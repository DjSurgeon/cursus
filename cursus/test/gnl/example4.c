/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:56:21 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/10 11:15:50 by sergio-jime      ###   ########.fr       */
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

	static char *s[20] = "hi";

	int i = 4;

	s[3] = 'g';
	s[2] = 'f';
	printf("=====\n");
	printf("%s", s);
}
int main(void)
{
	print_var();
	print_var();
	print_var();
	
	return (0);
}