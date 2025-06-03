/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:56:19 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/03 23:49:36 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
Voy a crear una función que coja los argumentos y los separe para luego 
validarlo esta funcion trabaja en chars.
*/
char	**argument_to_array(char **argv)
{
	char	**c_array;

	c_array = ft_split(argv[1], ' ');
	return (c_array);
}

/*
Una vez validados los chars, los pasamos a un array de ints para verificar 
los duplicados
*/
int	*char_array_to_int_array(char **argv)
{
	int		i;
	int		*i_array;
	long	number;

	i = 0;
	while (argv[i] != NULL)
		i++;
	i_array = ft_calloc(i + 1, sizeof(int));
	if (i_array == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (argv[i] != NULL)
	{
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (free(i_array), NULL);
		i_array[i] = (int)number;
		i++;
	}
	return (i_array);
}
