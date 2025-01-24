/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:47:58 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/24 17:34:57 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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