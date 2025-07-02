/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:03 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 18:30:25 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * paarsear color
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
 * array de numeros
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
			return (free(color), false);
		if (color[1])
		{
			if (!is_valid_hexa(color[1]))
				return (free(color), false);
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
 * parse la linea
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
 * This function processes a line of space-separated z-coordinates values,
 * counting the number of values (width) and tracking line numbers (height).
 * It validates consistent witdh across all lines of the map.
 * @param line The current line being processed from the map file.
 * @param map Pointer to the t_sizemap structure storing map dimensions.
 * @return void Exits program with EXIT_FAILURE if inconsistent width
 * is detected.
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
