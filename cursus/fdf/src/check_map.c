/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:52:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/22 16:44:32 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file check_map.c
 * @brief Reads and validates the map file line by line.
 * Processes the map file line by line, performing:
 * 1 - Line-by-line reading using get_next_line().
 * 2 - Format validation for each line.
 * 3 - Height calculation for valid maps.
 * 4 - Comprehensive error handling and resource cleanup.
 * @note Manage memory for each line read.
 * @note Sets the map->height field upon successful completion.
 * @note Closes the file descriptor on validation failure.
 * @param fd Valid file descriptor for the opened map file.
 * @param map Pointer to t_sizemap structure to store height information.
 * @return bool true if all lines are valid and file is fully read,
 * false if any line fails validation.
 * @warning The file descriptor must be valid and positioned at start.
 * @warning The map structure must be properly initialized.
 */
static bool	read_map(int fd, t_sizemap *map)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			map->height = i;
			return (free(line), true);
		}
		if (!validate_format(line, map))
		{
			free(line);
			close(fd);
			line = get_next_line(fd);
			return (false);
		}
		free(line);
		i++;
	}
	return (free(line), true);
}

/**
 * @file check_map.c
 * @brief Orchestrates the map validation process.
 * Manages the end-to-end validation workflow for FDF map files, including:
 * 1 - Initial map content reading and validation.
 * 2 - File reopening for coordinate processing.
 * 3 - Coordinate matrix creation.
 * @note Performs comprehensive error handling and resource cleanup.
 * @note Manages file descriptor lifecycle (closes/reopens as needed).
 * @param finalpath Absolute path to the map file being validated.
 * @param fd Valid file descriptor for the opened map file.
 * @param map Pointer to pre-allocated t_sizemap structure (may be NULL).
 * @return t_sizemap* On success: Fully populated map structure.
 * On failure: NULL (with all resources properly cleaned up).
 * @warning The caller must ensure 'finalpath' is valid and accessible.
 * @warning The input file descriptor must be valid and positioned at start. 
 */
t_sizemap	*validate_map(char *finalpath, int fd, t_sizemap *map)
{
	if (!read_map(fd, map))
		return (free(map), NULL);
	close(fd);
	fd = open_path(finalpath);
	if (fd == -1)
		return (NULL);
	map = create_coordinates(map, fd);
	if (map == NULL)
		return (free(map), NULL);
	return (map);
}
