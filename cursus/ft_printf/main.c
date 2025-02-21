/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:32:33 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/18 12:45:20 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int a = ft_printf("   %k  ");
	int b = printf("   %k  ");
	
	ft_printf("-> ft %\n");
	printf("-> lb %\n");
	
	ft_printf("%d\n", a);
	printf("%d\n", b);
	
	// ft_printf("%d", ft_printf("%"));
	// printf("\n");
	// printf("%d", printf("%"));

	// ft_printf("%d\n", "%");
	// printf("\n");
	// printf("%d\n", "%");
	// ft_printf("%d\n", ft_printf("%"));
	// printf("%d\n", printf("%"));

	// ft_printf("%d\n", ft_printf("%\n", "Hi!"));
	// printf("%d\n", printf("%\n", "Hi!"));
	
	// ft_printf("%d\n", ft_printf("%sblabla%\n", "Hi!"));
	// printf("%d\n", printf("%sblabla%\n", "Hi!"));
	
	return (0);
}