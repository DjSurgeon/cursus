/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:09:29 by sergio-jimene     #+#    #+#             */
/*   Updated: 2025/01/24 19:57:20 by sergio-jimene    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * description: converts the string pointed to by nptr to int. ascii to integer
 * param: const char pointer
 * return: int value or 0 on error
 */

#include <unistd.h>
#include <stdio.h>

static int isspace(int c)
{
	if (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == 32)
		return (1);
	return (0);
}

int	atoi(const char *nptr)
{
	int		result;
	int		sign;
	size_t	i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] != '\0' && isspace(nptr[i] == 1))
		i++;
	if(nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result  * sign);
}
int main(void)
{
	char	*n;

	n = "-207657";
	printf("%d\n", atoi(n));
	return (0);
}
