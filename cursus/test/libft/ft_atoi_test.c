/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:35:33 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/28 12:01:50 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* int ft_isspace(int c)
{
    if (c == 32 || c == '\f' || c == '\n' 
        || c == '\r' || c == '\t' || c == '\v')
    {
        return (1);
    }
    return (0);
}

int ft_atoi(const char *str)
{
    int sign;
    int r;
    r = 0; // inicializamos el resultado en 0
    sign = 1; // inicializamos el signo positivo

    while (ft_isspace(*str) == 1) // Verificamos los espacios del principio
                {
        str++;
    }
    if (*str == '-' || *str == '+') // verificamos los signos
    {
        if (*str == '-')
        {
        sign = -1; // manejamos el signo
        }
        str++; // si es positivo avanzamos
    }
    while (*str >= '0' && *str <= '9') // verificamos los numeros
    {
        r = r * 10 + (*str - '0'); // Empezamos a contar por la unidad mas a la izquierda
                // Se multiplica por 10 para avanzar un decena, sistema decimal.
        str++;
    }
    return (r * sign); // retornamos el numero total y le aplicamos el signo
i} */

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
    printf("%d\n", ft_atoi(number1)); // expect 1234
    printf("%d\n", ft_atoi(number2)); // expect -2147483648
    printf("%d\n", ft_atoi(number3)); // expect 2147483647
    return (0);
}