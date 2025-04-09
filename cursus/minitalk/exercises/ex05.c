/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:26:40 by serjimen          #+#    #+#             */
/*   Updated: 2025/04/09 14:16:00 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	binary_decimal(char *numb)
{
	size_t	i;
	int		result;
	int		power;


	i = 0;
	result = 0;
	power = 7;
	while (i <= 7)
	{
		if(numb[i] == '1')
			result += 1 << power;
		else if(numb[i] == '0')
			result += 0;
		i++;
		power--;
	}
	return (result);
}

int main(void)
{
	int 	n;
	char	*binary;
	int		result;

	n = 65; // 0100 0001
	binary = "00000011";
	result = binary_decimal(binary);

	printf("%d", result);
	return (0);
}
