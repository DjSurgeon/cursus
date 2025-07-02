/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:52:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 18:33:37 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * read file
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
			map->heigth = i;
			return (free(line), true);
		}
		if (!validate_format(line, map))
			return (free(line), false);
		free(line);
		i++;
	}
	return (free(line), true);
}

/**
 * create t_sizemap struct
 */
static t_sizemap	*create_sizemap(t_sizemap *map)
{
	map = ft_calloc(1, sizeof(t_sizemap));
	if (!map)
		return (print_error("Error Memory Allocation"), NULL);
	return (map);
}

/**
 * check file
 */
bool	validate_map(char *finalpath, int fd)
{
	t_sizemap	*map;

	map = NULL;
	map = create_sizemap(map);
	if (!map)
		return (false);
	if (!read_map(fd, map))
		return (free(map), false);
	close(fd);
	fd = open_path(finalpath);
	if (fd == -1)
		return (false);
	// create_coordinates(map, fd);
	return (free(map), true);
}
