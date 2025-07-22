/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:03 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/22 16:55:40 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Parses a coordinate string into its numerical and color components.
 * Split a coordinate string (format: "number, color") into
 * separate components.
 * Handles both simple numbers with aassociated color codes.
 * @param line Coordinate string to parse.
 * @return char** Array of strings where:
 * - [0] = z-coordinate value.
 * - [1] = color code (if present).
 * NULL if memory allocation fails.
 */
static char	**parse_color(char *line)
{
	char	**color;

	color = ft_split(line, ',');
	if (!color)
		return (NULL);
	return (color);
}

/**
 * @brief Validates an array of coordinate strings.
 * Processes each coordinate string in the array, validating:
 * - The numerical part is a valid integer.
 * - The color part (if present) is a valid hexadecimal code.
 * - Consistent width across all lines of the map.
 * @param str Array of coordinate strings.
 * @param map Pointer to t_sizemap structure for storing/validating dimensions.
 * @return true If all coordinates are valid and width is consistent.
 * @return false If any validation fails (with resources cleaned up).
 */
static bool	is_valid_array(char **str, t_sizemap *map)
{
	char	**color;
	int		i;

	i = 0;
	while (str[i])
	{
		color = parse_color(str[i]);
		if (!color)
			return (false);
		if (!is_valid_number(color[0]))
			return (free_matrix(color), false);
		if (color[1])
		{
			if (!is_valid_hexa(color[1]))
				return (free_matrix(color), false);
		}
		free_matrix(color);
		i++;
	}
	map->width = i;
	if (map->expected_width == 0)
		map->expected_width = i;
	return (true);
}

/**
 * @brief Slpits a map line into individual coordinate strings.
 * Separates a line of space-separated coordinate values into an
 * array of individual coordinate strings.
 * @param line The map line to split.
 * @return char** Array of coordinate strings, or NULL on
 * allocation failure.
 */
static char	**parse_line(char *line)
{
	char	**line_z;

	line_z = ft_split(line, 32);
	if (!line_z)
		return (NULL);
	return (line_z);
}

/**
 * @file check_valid_map.c
 * @brief Validates a single line of map coordinates and updates map dimensions.
 * Performs comprehensive validation of a map file line containing:
 * - Space separated coordinates values.
 * - Optional color values in hexadecimal format.
 * - Validates both syntax and semantic consistency.
 * @note Performs complete memory cleanup in all cases.
 * @note Verifies width consistency with previous lines.
 * @param line The current line being processed (null-terminated string).
 * @param map Pointer to t_sizemap structure for dimension tracking.
 * @return bool true if line format is valid and width matches previous lines,
 * false if any validation fails (with automatic resource cleanup).
 * @warning The line string must be null-terminated.
 * @warning Modifies map->width on first successful line validation.
 */
bool	validate_format(char *line, t_sizemap *map)
{
	char	**line_z;

	line_z = parse_line(line);
	if (line_z == NULL)
		return (false);
	if (!is_valid_array(line_z, map))
		return (free_matrix(line_z), false);
	if (!is_correct_width(map))
		return (free_matrix(line_z), false);
	return (free_matrix(line_z), true);
}
