/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:34:50 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/16 14:01:25 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the string is empty.
 * @param c_array The char array.
 * @return True is the string is empty, false otherwise.
 */

static bool	is_empty(char **c_array)
{
	if (c_array[0] == NULL)
		return (true);
	return (false);
}

/**
 * @brief Checks if the string contains letters. (A to Z) and (a to z)
 * @param c_array The char array.
 * @return True if the string contain letters, false otherwise
 */
static bool	is_letter(char **c_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c_array[i] != NULL)
	{
		j = 0;
		while (c_array[i][j] != '\0')
		{
			if (ft_isalpha(c_array[i][j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

/**
 * @brief Checks if the digit are in valid format, only one sign
 * before the number. (-9) (+1)
 * Checks too if are any strange symbol after the number. (8+) (9$)
 * @param c_array The char array.
 * @return True in case of the numbers are in correct format, false otherwise.
 */
static bool	is_digit(char **c_array)
{
	int	i;
	int	j;

	i = 0;
	while (c_array[i] != NULL)
	{
		j = 0;
		while (c_array[i][j] != '\0')
		{
			if ((c_array[i][j] == '-' || c_array[i][j] == '+')
				&& ft_isdigit(c_array[i][j + 1]) && j == 0)
				j++;
			if (ft_isdigit(c_array[i][j]))
				j++;
			else if (!ft_isdigit(c_array[i][j]))
				return (false);
			else
				return (false);
		}
		i++;
	}
	return (true);
}

/**
 * @brief Check if the number is duplicated.
 * @param i_array The array of ints.
 * @param length The length of the array.
 * @return False if the number is duplicated, true otherwise.
 */
static bool	is_duplicated(int *i_array, int length)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	if (i_array == NULL)
		return (false);
	while (i < length)
	{
		temp = i_array[i];
		j = i + 1;
		while (j < length)
		{
			if (temp == i_array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

/**
 * @brief Function to checks all the errors.
 * @param c_array The char array.
 * @return True if all checks are ok, false otherwise
 */
bool	check_array(char **c_array)
{
	int	*i_array;
	int	length;

	length = 0;
	while (c_array[length] != NULL)
		length++;
	if (is_empty(c_array))
		return (ft_puterror_fd("Error\n", 2), false);
	if (is_letter(c_array))
		return (ft_puterror_fd("Error\n", 2), false);
	if (!is_digit(c_array))
		return (ft_puterror_fd("Error\n", 2), false);
	i_array = char_array_to_int_array(c_array, length);
	if (i_array == NULL)
		return (ft_puterror_fd("Error\n", 2), false);
	if (is_duplicated(i_array, length))
		return (ft_puterror_fd("Error\n", 2), false);
	free(i_array);
	return (true);
}
