/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:56:19 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/16 17:29:39 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Splits a single string into an array of strings bassed on spaces.
 * This function is used when the program receives a single quoted argument
 * containing numbers.
 * @param argv The input string to be split.
 * @return A dynamically allocated array of strings, or NULL if the input
 * is NULL or memory allocation fails.
 * @note The caller is responsible for freeing the returned array.
 * @warning Depends on ft_split, which must correctly handle memory allocation
 * and splitting.
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
 * @brief Converts an array of strings into an array of integers.
 * This function takes an array of strings and converts each element into
 * its corresponding integer value, storing them in a dynamically
 * allocated array.
 * @param argv The array of strings to convert.
 * @param length The number of elements in the array.
 * @return A dynamically alocated array of integers, or NULL if memory
 * allocation fails or if any string cannot be converted to an integer
 * within the int range.
 * @note Checks for integer overflow, underflow and excesive string
 * length.
 * @warning The caller must free the returned array to prevent memory leaks.
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
		if (number > INT_MAX || number < INT_MIN
			|| ft_ps_countstr(argv[length]) > 10)
			return (free(i_array), NULL);
		i_array[length] = (int)number;
		length++;
	}
	return (i_array);
}
