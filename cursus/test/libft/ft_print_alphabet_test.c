/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:51:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/04 10:02:17 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';

	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}
