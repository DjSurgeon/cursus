/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:56:19 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/04 13:31:35 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief function to split the arguments in case argc == 2
 * @param argv the string
 * @return a array of arrays
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
 * @brief function to pass the char array to array of ints
 * @param argv the array of chars
 * @return the array of ints
 */
int	*char_array_to_int_array(char **argv)
{
	int		i;
	int		*i_array;
	long	number;

	i = 0;
	while (argv[i] != NULL)
		i++;
	i_array = ft_calloc(i, sizeof(int));
	if (i_array == NULL)
		return (NULL);
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
