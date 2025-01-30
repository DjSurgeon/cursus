/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:50:15 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/29 15:00:44 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_count_strings(const char *string, char character)
{
	int sub_strings;	// variable para el numero de sub strings
	size_t i;			// iterador
	int is_in_string;	// flag para saber si estoy dentro de una string

	sub_strings = 0; // inicializamos en 0
	i = 0;
	// is_in_string = 0 estoy fuera de la string, 1 estoy en dentro de la string
	while (string[i] != '\0')
	{
		is_in_string = 0; // fuera de la string
		while (string[i] != '\0' && string[i] == character)
		{
			i++;
		}
		while (string[i] != '\0' && string[i] != character)
		{
			if (is_in_string == 0)
			{
				sub_strings++;
				is_in_string = 1; // dentro de la string
			}
			i++;
		}
	}
	return (sub_strings); // retornamos el numero de sub strings que tenemos
}
int	main(void)
{
	char	*string = "xxxHOLAxx42xxxMADRIDxxx";
	char	character = 'x';
	char	*string2 = "     HO LA 4 2 \n\n MAD RID";
	char	character2 = ' ';



	printf("%i\n", ft_count_strings(string, character));
	printf("%i\n", ft_count_strings(string2, character2));


	return (0);
}