/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:03 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 22:10:56 by sergio-jime      ###   ########.fr       */
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
 * @brief Validates a single line of map coordinatea and updates map dimensions.
 * Processes a line of space-separated coordinate values, validating:
 * - The format of each coordinate (number + optional color).
 * - Consistent width across all lines of the map.
 * @param line The current line being processed from the map file.
 * @param map Pointer to the t_sizemap structure for storing map dimensions.
 * @return true If the line is valid and width is consistent.
 * @return false If validation fails (with resources cleaned up).
 */
bool	validate_format(char *line, t_sizemap *map)
{
	char			**line_z;

	line_z = parse_line(line);
	if (line_z == NULL)
		return (false);
	if (!is_valid_array(line_z, map))
		return (free_matrix(line_z), false);
	if (!is_correct_width(map))
		return (false);
	return (free_matrix(line_z), true);
}
