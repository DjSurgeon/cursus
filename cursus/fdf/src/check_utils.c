/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:16:29 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/22 09:26:16 by sergio-jime      ###   ########.fr       */
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
		return (print_error("Error Invalid File Descriptor\n"), -1);
	return (fd);
}

/**
 * @brief Validates a hexadecimal color code string.
 * Checks if the string conforms to the format "0xRRGGBB" where:
 * - Starts with "0x".
 * - Contains 6 hexadecimal digits.
 * - Only valid hex characters (0-9, a-f, A-F).
 * @param str String to validate as hezadecimal color code.
 * @return true If the string is a valid hexadecimal color.
 * @return false If invalid format (with error message printed).
 */
bool	is_valid_hexa(char *str)
{
	int	i;

	if (str[0] == '0' && str[1] == 'x' && str[2] != '\0')
		i = 2;
	else
		return (print_error("Invalid hexadecimal\n"), false);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isxdigit(str[i]) == 0)
			return (print_error("Invalid hexadecimal\n"), false);
		i++;
	}
	return (true);
}

/**
 * @brief Validates a numerical string representation.
 * Checks if the string represents a valid integer with:
 * - Optional leading sign (+ or -)-
 * - At least one digit after any sign.
 * - Only digit characters (0-9).
 * @param str String to validate as numerical.
 * @return true If the string is a valid number.
 * @return false If invalid format (with error message).
 */
bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (str[i] == '\0')
		return (print_error("Invalid sign"), false);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0)
			return (print_error("Invalid character\n"), false);
		i++;
	}
	return (true);
}

/**
 * @brief Validates consistent map width across lines.
 * Compares the current line's width with the expected width
 * established from the first line of the map. Ensures all
 * lines have the same number of coordinates.
 * @param map Pointer to t_sizemap structure storing width information.
 * @return true If width matches expected value.
 * @return false If consistent width (with error message).
 */
bool	is_correct_width(t_sizemap *map)
{
	if (map->expected_width != 0 && map->expected_width != map->width)
	{
		print_error("Error different width map");
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
		return (print_error("Error Memory Allocation"), NULL);
	return (map);
}
