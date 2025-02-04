/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_testv2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:53:03 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/04 14:10:24 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_count_digits(int n)
{
	int	result;

	result = 0;
	if(n == 0)
		return (1);
	else if(n == -2147483648)
		return (11);
	else if(n < 0)
	{
		result++;
		n = -n;
	}
	while(n != 0)
	{
		result++;
		n /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*result;
	int		position;
	
	digits = ft_count_digits(n);
	position = digits - 1;
	result = malloc(digits * sizeof(char) + 1);
	if (!result)
		return (NULL);
	if (n == -2147483648)
		return (result = "-2147483648");
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		result[position] = (n % 10) + '0';
		n /= 10;
		position--; 
	}
	result[position] = n + '0';
	result[digits] = '\0';
	return (result);
}
int main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}