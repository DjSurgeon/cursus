/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:35:33 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/13 16:37:59 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static int	ft_isspace(int c)
{
	if (c == 32 || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
    int		result;
    size_t  i;

	result = 0;
	sign = 1;
    i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
    {
		if (str[i] == '-')
			sign = -1;
	    i++;
    }
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
int main(void)
{
    const char *number1 = "1234";
    const char *number2 = "-2147483648";
    const char *number3 = "2147483647";
    const char *empty = "";

    printf("%d\n", ft_atoi(number1)); // expect 1234
    printf("%d\n", ft_atoi(number2)); // expect -2147483648
    printf("%d\n", ft_atoi(number3)); // expect 2147483647
    printf("%d\n", ft_atoi(empty)); // expect 0
    return (0);
}
