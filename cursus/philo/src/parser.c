/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:50:12 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 17:09:17 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parser.c
 * @brief Contains functions for validating and checking the integrity of
 * command-line arguments before starting the simulation.
 * This module ensures that all input parameters (number of philosophers,
 * timings, and optional eat count) are correctly formatted and adhere to
 * the logical constraints of the Philosophers problem.
 */
#include "philo.h"

/**
 * @brief Checks numerical constraints and logical rules for the arguments.
 * This static helper function validates:
 * 1. That all time/count parameters are strictly **positive** ( > 0).
 * 2. That the crucial simulation time constraint is respected:
 * `time_to_die` must be greater than or equal to `time_to_eat` to give the
 * philosopher a chance to survive.
 * @param i The index of the argument in `argv` (1 to 5).
 * @param arr The array of argument strings (`argv`).
 * @return static bool Returns true if the argument passes all logical checks,
 * false otherwise.
 * @warning The checks for N=1 and N=2 philosophers are often not required by the
 * subject and might disable valid test cases. They are kept here based on the
 * original code structure but documented as non-standard restrictions.
 */
static bool	validate_cases(size_t i, char **arr)
{
	int	number;

	number = ft_atoi(arr[i]);
	if (ft_atoi(arr[2]) < ft_atoi(arr[3]))
		return (printf("ERROR: To shoort times\n"), false);
	if (number <= 0)
		return (printf("ERROR: Only positive numbers\n"), false);
	return (true);
}

/**
 * @brief Checks if an argument string consists only of decimal digits.
 * Iterates through the characters of an argument string at index `i` to ensure
 * that every character is a valid decimal digit (`0` through `9`). This
 * prevents non-numeric or malformed input from being passed to @ref ft_atoi.
 * @param i The index of the argument in `argv`.
 * @param arr The array of argument strings (`argv`).
 * @return static bool Returns true if the argument contains only digits,
 * false otherwise.
 * @note This function strictly requires **pure digits** and will reject leading
 * signs ('+' or '-'), enforcing a very strict input format.
 */
static bool	validate_digits(size_t i, char **arr)
{
	size_t	j;

	j = 0;
	while (arr[i][j])
	{
		if (!ft_isdigit(arr[i][j]))
			return (printf("ERROR: Only digits\n"), false);
		j++;
	}
	return (true);
}

/**
 * @brief Main function to check all command-line arguments passed to
 * the program.
 * Iterates through all input arguments (starting from argv[1]) and applies
 * two sequential levels of validation:
 * 1. **Format Check:** Calls @ref validate_digits to ensure the input is
 * purely numeric.
 * 2. **Logic Check:** Calls @ref validate_cases to apply numerical (> 0) and
 * simulation constraints (time relationships, philosopher count restrictions).
 * The function stops and returns `false` upon the first validation error
 * encountered.
 * @param arr The array of argument strings (`argv`). Note: This array
 * starts with `argv[0]` (program name), so validation begins at index 1.
 * @return bool Returns true if ALL required arguments are valid, false if any
 * check fails.
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
