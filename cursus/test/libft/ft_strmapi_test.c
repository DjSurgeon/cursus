/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:10:29 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/24 17:33:40 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
// #include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
char	*ft_to_upper(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z') // Verifica si el carácter es una letra minúscula
        return (c - 32); // Convierte a mayúscula
    return (c); // Si no es minúscula, devuelve el carácter original
}
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	new_string_len; // la nueva string medira exactamente lo mismo que la que se le aplica la funcion
	size_t	i; // para iterar sobre las cadenas
	char	*new_string;

	if(s == NULL) // si la string es null, se devuelve null
		return (NULL);
	new_string_len = ft_strlen(s); // medimos la cadena
	i = 0;
	new_string = (char *)malloc(new_string_len + 1); // reservamos la memoria
	if (!new_string)
		return (NULL);
	while (s[i] != '\0')
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return ( new_string);
}
int main(void)
{
	char string[] = "hola mundo";
	char *result;
	
	result = ft_strmapi(string, ft_to_upper);
	write(1, result, ft_strlen(result));

	return (0);
}