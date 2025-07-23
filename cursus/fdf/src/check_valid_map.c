/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:03 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/23 14:07:25 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file check_valid_map.c
 * @brief Parses a coordinate string into its numerical and color components.
 * Splits a coordinate string in the format "z,color" into separate components:
 * - The z-coordinate (elevation value).
 * - Optinoal color in hexadecimal format.
 * @note Uses coma (',') as the delimiter between components.
 * @note The returned array and strings must be freed by caller.
 * @note Handles both simple z-values and colored coordinates.
 * @note Empty color components will be returned as NULL.
 * @param line Coordinate string to parse (format "z" or "z,color").
 * @return char** Array of strings where:
 * - [0] = z-coordinate value as string.
 * - [1] = color code as string (NULL if not present).
 * - NULL if memory allocation fails.
 * @warning The input string must not be NULL.
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
 * @file check_valid_map.c
 * @brief Validates an array of coordinate strings.
 * Performs comprehensive validation of coordinate strings from a map file,
 * checking both the numerical and optional color components. Also maintains
 * and validates consistent map width across all lines.
 * @note Validates both the numeric and color components of each coordinate.
 * @note Tracks and enforces consistent map width.
 * @note Automatically cleans up allocated resources on validation failure.
 * @note Sets expected_width on first validation.
 * @param str Array of coordinate strings (null-terminated array).
 * @param map Pointer to t_sizemap structure for dimension tracking.
 * @return bool true If all coordinates are valid and width is consistent.
 * @return bool false If any validation fails (with resources cleaned up).
 * @warning The input array must be NULL-terminated.
 * @warning The map structure must be properly initialized.
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
 * @file check_valid_map.c
 * @brief Splits a map line into individual coordenate strings.
 * Processes a line from the map file and separates if into an array
 * of strings representing individual coordinates. The splitting is done
 * using space character (ASCII '32') as delimiter.
 * @note The returned array and all its strings must be freed by the caller.
 * @param line The map line to process (null-terminated string).
 * @return char** On success: Array of null-terminated coordinate strings,
 * on failure: NULL.
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
