/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:12:00 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/25 10:19:42 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
// #include "libft.h"

char	*ft_to_upper(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z') // Verifica si el carácter es una letra minúscula
        return (c - 32); // Convierte a mayúscula
    return (c); // Si no es minúscula, devuelve el carácter original
}
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t  i;

	i = 0;
	if (s == NULL || f == NULL) // verificamos nulos
	{
		return;
	}
	while (s[i] != '\0')
	{
		f(i, &s[i]); // modificamos la cadena desde la funcion &s[i]
		i++;
	}
}

int main(void)
{
	char string[] = "Hola Mundo";

	write(1, string, 10);
	ft_striteri(string, ft_to_upper);
	write(1, string, 10);

	return (0);
}