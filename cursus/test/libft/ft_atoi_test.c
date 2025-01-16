/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:35:33 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/16 15:34:38 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_isspace(int c)
{
    if (c == 32 || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
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
}
int main(void)
{
    const char *number = "1234";
    // TODO pasar un int a string
    printf("%d\n", ft_atoi(number));
    return (0);
}