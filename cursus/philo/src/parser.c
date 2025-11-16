/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:50:12 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 21:26:16 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parser.c
 * @brief Contains functions for validating and checking the integrity of
 * command-line arguments before starting the simulation.
 * This module ensures that all input parameters (number of philosophers,
 * timings, and optional eat count) are correctly formatted and adhere to
 * the numerical constraints required for the simulation.
 */
#include "philo.h"

/**
 * @brief Checks numerical constraints and logical rules for the arguments.
 * This static helper function validates:
 * 1. That the number does not exceed the `INT_MAX` limit or its string
 * length is too large (potential overflow check, assuming `ft_atol`
 * converts to `long`).
 * 2. That all time/count parameters are strictly **positive** ( > 0).
 * @param i The index of the argument in `argv` (1 to 5).
 * @param arr The array of argument strings (`argv`).
 * @return static bool Returns **true** if the argument passes all logical
 * checks, **false** otherwise. Prints an error message on failure.
 * @note Assumes the argument string has already been successfully converted
 * to a long for the check, implying a dependency on an external `ft_atol`
 * utility.
 * @warning The crucial logic that `time_to_die >= time_to_eat` is currently
 * missing in this function but should ideally be included in logical checks.
 */
static bool	validate_cases(size_t i, char **arr)
{
	long	number;
	int		len;

	len = ft_countstr(arr[i]);
	number = ft_atol(arr[i]);
	if (number > INT_MAX || len >= 11)
		return (printf("%s\n", ERROR), false);
	if (number <= 0)
		return (printf("%s\n", ERROR), false);
	return (true);
}

/**
 * @brief Checks if an argument string consists only of decimal digits.
 * Iterates through the characters of an argument string at index `i` to
 * ensure that every character is a valid decimal digit (`0` through `9`).
 * This prevents non-numeric or malformed input from being passed to
 * conversion functions.
 * @param i The index of the argument in `argv` (1 to 5).
 * @param arr The array of argument strings (`argv`).
 * @return static bool Returns **true** if the argument contains only digits,
 * **false** otherwise. Prints an error message on failure.
 * @note This function strictly requires **pure digits** and will reject signs
 * ('+' or '-').
 * @see ft_isdigit()
 */
static bool	validate_digits(size_t i, char **arr)
{
	size_t	j;

	j = 0;
	while (arr[i][j])
	{
		if (!ft_isdigit(arr[i][j]))
			return (printf("%s\n", ERROR), false);
		j++;
	}
	return (true);
}

/**
 * @brief Main function to check all command-line arguments passed to
 * the program.
 * Iterates through all input arguments (starting from `argv[1]`) and
 * applies two sequential levels of validation:
 * 1. **Format Check:** Calls @ref validate_digits to ensure the input is
 * purely numeric.
 * 2. **Logic Check:** Calls @ref validate_cases to apply numerical (> 0)
 * and overflow constraints.
 * The function stops and returns `false` upon the first validation error
 * encountered.
 * @param arr The array of argument strings (`argv`). Validation begins at
 * index 1.
 * @return bool Returns **true** if ALL required arguments are valid, **false**
 * if any check fails, printing an error message in the process.
 * @see validate_digits()
 * @see validate_cases()
 */
bool	check_arguments(char **arr)
{
	size_t	i;

	i = 1;
	while (arr[i])
	{
		if (!validate_digits(i, arr))
			return (false);
		if (!validate_cases(i, arr))
			return (false);
		i++;
	}
	return (true);
}
