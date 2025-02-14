/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:39:53 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/14 01:21:43 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{	
	int	count1 = 0;
	int	count2 = 0;
	
	ft_printf("Check chars\n");
	count1 = ft_printf("h %ca  %s\n", 'a', "42spain");
	count2 = printf("h %ca  %s\n", 'a', "42spain");

	printf("%i\n", count1);
	printf("%i\n", count2);
	
	ft_printf("Check ints\n");
	count1 = ft_printf("%d - %u - %d - %u\n%u - %u - %u\n", 0, 1234, -2198765, 2147483647, 123456789, 4567890876, 34567890, 23456789);
	count2 = printf("%d - %u - %d - %u\n%u - %u - %u\n", 0, 1234, -2198765, 2147483647, 123456789, 4567890876, 34567890, 23456789);
	
	printf("%i\n", count1);
	printf("%i\n", count2);
	
	return (0);
}