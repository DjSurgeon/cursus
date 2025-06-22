/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:34:42 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/23 00:38:47 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(void)
{
	ft_printf("Hola Mundo\n");
	perror("Error de apertura.");
	ft_printf("Error %d: %s\n", errno, strerror(errno));
	return (0);
}