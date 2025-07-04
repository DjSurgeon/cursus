/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:52:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/04 15:06:25 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Reads and validates the map file line by line.
 * Iterates through each line of the map file, validating the format
 * and counting the number of lines (height). Stores the final height
 * in the map structure upon successful completion.
 * @param fd File descriptor of the opened map file.
 * @param map Pointer to the t_sizemap structure for storing map dimensions.
 * @return true If all lines are valid and file fully processed.
 * @return false If any line fails validation (with error message).
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
 * @brief Orchestrates the map validation process.
 * Manages the full map validation workflow:
 * - Creates size tracking structure.
 * - Reads and validates file content line by line.
 * - Reopens file for additional processing.
 * @param finalpath Full path to the map file.
 * @param fd File descriptor of the opened map file.
 * @return true If all validation steps pas successfully.
 * @return false If any step fail (with appropiate error handling).
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
