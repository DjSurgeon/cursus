/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:34:50 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/16 18:12:02 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the array of strings is empty.
 * This function verifies whether the first element of the array is NULL,
 * which indicates an empty array.
 * @param c_array The array of strings to check.
 * @return True if the array is empty, false otherwise.
 */

static bool	is_empty(char **c_array)
{
	if (c_array[0] == NULL)
		return (true);
	return (false);
}

/**
 * @brief Checks if any string in the array contains alphabetical letters.
 * This function iterates through each string in the array and checks for
 * the presence of letters (A-Z, a-z), using ft_isalpha.
 * @param c_array The array of strings to check.
 * @return True if any string contains at least one letter, false if none do.
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
 * @brief Validate the format of each string in the array as an integer.
 * Ensures that each string reperesents a valid integer with:
 * - An optional single leading sign ('+' or '-') followed by digits.
 * - Only digits after the sign, with no additional characters.
 * Examples of invalid formats: "8+", "9$", "-+1", "12a".
 * @param c_array The array of strings to validate.
 * @return True if all strings are valid integers, false if any string has
 * an invalid format.
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
 * @brief Check for duplicate integers in the array.
 * This function iterates through the array to detect if any integer
 * appears more than once.
 * @param i_array The array of integers to check.
 * @param length The number of elements in the array.
 * @return True if any duplicate is found, false if all elements are unique.
 * @note If a duplicate is found, the funcion frees the array and returns true.
 * 
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
				return (free(i_array), true);
			j++;
		}
		i++;
	}
	return (false);
}

/**
 * @brief Validates the array of strings for use in push_swap.
 * This function performs a series of checks on the array:
 * - Ensure the array is not empty.
 * - Verifies that no string contains letters.
 * - Confirms that all strings represent valid integers.
 * - Converts the string to integers and checks for duplicates.
 * @param c_array The array of strings to validate.
 * @return True if all checks pass, false if any checks fails.
 * @note Prints "Error\n" to stderr and returns false if any check fails.
 */
bool	check_array(char **c_array)
{
	int	*i_array;
	int	length;

	length = 0;
	while (c_array[length] != NULL)
		length++;
	if (is_empty(c_array))
		return (ft_puterror_fd("Error\n"), false);
	if (is_letter(c_array))
		return (ft_puterror_fd("Error\n"), false);
	if (!is_digit(c_array))
		return (ft_puterror_fd("Error\n"), false);
	i_array = char_array_to_int_array(c_array, length);
	if (i_array == NULL)
		return (ft_puterror_fd("Error\n"), false);
	if (is_duplicated(i_array, length))
		return (ft_puterror_fd("Error\n"), false);
	free(i_array);
	return (true);
}
