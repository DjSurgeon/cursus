/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:56:19 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/16 14:02:00 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Function to split the arguments in case argc == 2.
 * @param argv The string.
 * @return A array of arrays.
 */
char	**argument_to_array(char *argv)
{
	char	**c_array;

	if (argv == NULL)
		return (NULL);
	c_array = ft_split(argv, ' ');
	return (c_array);
}

/**
 * @brief Function to pass the char array to array of ints
 * @param argv The array of chars
 * @param length The Length of the array.
 * @return The array of ints.
 */
int	*char_array_to_int_array(char **argv, int length)
{
	int		*i_array;
	long	number;

	i_array = ft_calloc(length, sizeof(int));
	if (i_array == NULL)
		return (NULL);
	length = 0;
	while (argv[length] != NULL)
	{
		number = ft_atol(argv[length]);
		if (number > INT_MAX || number < INT_MIN || ft_ps_countstr(argv[length]) > 10)
			return (free(i_array), NULL);
		i_array[length] = (int)number;
		length++;
	}
	return (i_array);
}
