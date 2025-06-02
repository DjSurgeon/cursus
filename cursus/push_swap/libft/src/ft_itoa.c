/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:29:49 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/13 12:50:44 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: generate a string equal to int value
**	parameter: int positive or negative
**	return: the string of int value or NULL if malloc fail
*/

#include "libft.h"

static size_t	intlen(long n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
	{
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	reverse_string(char *s, size_t len)
{
	size_t	start;
	size_t	end;
	char	swap;

	start = 0;
	end = len - 1;
	{
		while (start < end)
		{
			swap = s[start];
			s[start] = s[end];
			s[end] = swap;
			start++;
			end--;
		}
	}
}

static char	*aux_itoa(char *s, long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*result;
	int		negative;
	long	num;

	num = n;
	len = intlen(num);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	negative = 1;
	if (n < 0)
	{
		num = -num;
		negative = 0;
	}
	aux_itoa(result, num);
	if (negative != 1)
	{
		result[len - 1] = '-';
	}
	reverse_string(result, len);
	result[len] = '\0';
	return (result);
}
