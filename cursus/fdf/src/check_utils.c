/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:16:29 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/23 16:37:37 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file check_utils.c
 * @brief Opens a map file and returns its file descriptor.
 * Attemps to open the specified file in read-only mode with the following
 * characteristics:
 * - Uses low-level POSIX open() system call.
 * - Provides standardized error handling.
 * - Returns a valid file descriptor or -1 on failure.
 * @note The caller must be responsible for closing the file descriptor
 * when done.
 * @note Uses O_RDONLY flag (read-only mode).
 * @param str Absolute or relative path to the map file. Must not be NULL.
 * @return int On success: Valid file descriptor, On failure: -1
 * (with error message printed to stderr).
 */
int	open_path(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (print_error("Error: Invalid file descriptor\n"), -1);
	return (fd);
}

/**
 * @file check_utils.c
 * @brief Validates a hexadecimal color code string.
 * Verifies that a string conforms to the standard hexadecimal color format:
 * - Must begin with "0x" prefix.
 * - Only allows characters 0-9, a-f, A-F.
 * - Properly terminated (null or newline).
 * @note Requires strict "0x" prefix (case sensitive).
 * @note Case-insensitive for hex digits (a-f and A-F both allowed).
 * @note Prints error messages to stderr on validation failures.
 * @param str String to validate as hexadecimal color code.
 * @return bool true If the string is a valid hexadecimal color.
 * @return bool false If invalid format (with descriptive error message).
 */
bool	is_valid_hexa(char *str)
{
	int	i;

	if (str[0] == '0' && str[1] == 'x' && str[2] != '\0')
		i = 2;
	else
		return (print_error("Error: Invalid 0x prefix\n"), false);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isxdigit(str[i]) == 0)
			return (print_error("Error: Invalid hexadecimal\n"), false);
		i++;
	}
	return (true);
}

/**
 * @file check_utils.c
 * @brief Validates a string as a properly formated number.
 * Performs comprehensive validation string representing an integer number,
 * checking for:
 * - Optional leading sign character (+ or -).
 * - At least one following digit.
 * - Only valid digit characters (0-9).
 * - Proper termination (null or newline).
 * @note Rejects any non-digit characters.
 * @note Prints error messages to stderr on validation failures.
 * @param str String to validate as numerical.
 * @return bool true If the string is a valid number format.
 * @return false If invalid format (with descriptive error message).
 */
bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (str[i] == '\0')
		return (print_error("Error: Missing digits after sign\n"), false);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0)
			return (print_error("Error: Non-digit character\n"), false);
		i++;
	}
	return (true);
}

/**
 * @file check_utils.c
 * @brief Validates consistent map width across all lines.
 * Ensures the current line's coordinate count matches the expected width
 * established from the first line of the map file. This validation is
 * critical for maintaining proper map structure in the FDF wireframe.
 * @note First line establishes expected width for subsequent lines.
 * @note Always returns true for first line.
 * @note Critical for maintaining rectangular map structure.
 * @param map Pointer to t_sizemap structure storing width information.
 * @return true If width matches expected value or is first line.
 * @return false If width mismatch (with descriptive error message).
 * @warning The map structure must contain valid width values.
 * @warning Terminates validation pipeline on failure.
 */
bool	is_correct_width(t_sizemap *map)
{
	if (map->expected_width != 0 && map->expected_width != map->width)
	{
		print_error("Error: Inconsistent width map\n");
		return (false);
	}
	return (true);
}

/**
 * @file check_utils.c
 * @brief Allocates and initializes a t_sizemap structure.
 * This function dynamically allocates memory for a t_sizemap structure
 * using ft_calloc, which ensures all members are zero-initialized.
 * The structure is used to store map dimensions and coordinate data
 * in the FDF wireframe viewer.
 * @note Memory allocated by this function must be freed when no longer needed.
 * @param map Pointer parameter maintained for interface consistency.
 * The value is not used internally.
 * @return t_sizemap* On succes: Pointer to newly allocated t_sizemap
 * structure. On failure: NULL (with error message printed to stderr).
 */
t_sizemap	*create_sizemap(t_sizemap *map)
{
	map = ft_calloc(1, sizeof(t_sizemap));
	if (!map)
		return (print_error("Error: Memory allocation\n"), NULL);
	return (map);
}
