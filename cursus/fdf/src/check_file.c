/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:52:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 11:51:32 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * check digits
 */
static bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	// TODO: Validar comas detras del número
	if (str[i] == '\0')
		return (perror("Invalid character"), free(str), false);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0)
			return (perror("Invalid character"), free(str), false);
		i++;
	}
	return (true);
}

/**
 * check width
 */

static bool	is_correct_width(t_sizemap *map)
{
	if (map->check_width != 0 && map->check_width != map->width)
	{
		// free(line);
		perror("Error different width map");
		return (false);
	}
	return (true);
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
static bool	check_coordinate(char *line, t_sizemap *map)
{
	char			**axis_z;
	int				i;
	static int		j = 1;

	i = 0;
	axis_z = ft_split(line, 32);
	while (axis_z[i])
	{
		if (!is_valid_number(axis_z[i]))
			return (free(axis_z), false);
		free(axis_z[i]);
		i++;
	}
	free(axis_z);
	map->width = i;
	map->heigth = j++;
	if (!is_correct_width(map))
		return (false);
	map->check_width = map->width;
	return (true);
}

/**
 * read file
 */
static bool	read_file(int fd, t_sizemap *map)
{
	char	*line;
	
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			//ft_printf("width %d, heigth %d\n", map->width, map->heigth);
			//free(map);
			return (true);
		}
		if (!check_coordinate(line, map))
			return (free(map), free(line), false);
		free(line);
	}
	return (true);
}

/**
 * check file
 */
bool	check_file(char *finalpath, int fd)
{
	t_sizemap	*map;

	map = NULL;
	map = ft_calloc(1, sizeof(t_sizemap));
	if (!map)
	{
		free(map);
		close (fd);
		return (print_error("Error memory allocation check_file()"),
			false);
	}
	else
	{
		if (!read_file(fd, map))
			return (false);
		close(fd);
		fd = open(finalpath, O_RDONLY);
		if (fd < 0)
			return (print_error("Error open()"), false);
		create_coordinates(map, fd);
		free(map);
	}
	return (free(finalpath), true);
}
