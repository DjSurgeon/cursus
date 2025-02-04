/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet_test.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:00:20 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/04 10:03:09 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >='a')
	{
		write(1, &c, 1);
		c--;
	}
}
int main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}