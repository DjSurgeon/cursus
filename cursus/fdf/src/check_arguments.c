/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:55:52 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/30 14:59:20 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
static void	check_coordinate(char *line, t_sizemap *map)
{
	char			**axis_z;
	int				i;
	static int		j = 1;

	i = 0;
	axis_z = ft_split(line, 32);
	while (axis_z[i])
	{
		free(axis_z[i]);
		i++;
	}
	map->width = i;
	map->heigth = j++;
	if (map->check_width != 0 && map->check_width != map->width)
	{
		perror("Error different width map");
		exit (EXIT_FAILURE);
	}
	map->check_width = map->width;
	free(axis_z);
}

/**
 * @brief Validates file extension and processes map content line
 * by line.
 * Checks if the file has correct .fdf extension. If valid,
 * reads the file line by line, processing each line through check_coordinate()
 * Upon reaching end of file, outputs map dimensions and exits.
 * @param finalpath Full path to the map file being validated.
 * @param fd File descriptor of the opened map file.
 * @return void Exits program with EXIT_FAILURE on invalid extension,
 * or EXIT_SUCCESS after processing entire file.
 */
static void	check_extension(char *finalpath, int fd)
{
	t_sizemap	*map;
	char		*line;

	map = NULL;
	map = malloc(sizeof(t_sizemap));
	if (ft_strnstr(finalpath, ".fdf", ft_strlen(finalpath)) == NULL)
	{
		perror("Error extension");
		free(finalpath);
		exit (EXIT_FAILURE);
	}
	else
	{
		while (1)
		{
			line = get_next_line(fd);
			if (line == NULL)
			{
				free(finalpath);
				// TODO: eje z
				ft_printf("width %d, heigth %d\n", map->width, map->heigth);
				free(map);
				exit(EXIT_SUCCESS);
			}
			check_coordinate(line, map);
			free(line);
		}
	}
}

/**
 * @brief Main map validation function: handles path construction and
 * file access.
 * Construct the full path to the map file, attempts to open it, and initiates
 * the validation process throught check_extension(). 
 * Handles file access errors.
 * @param str Map filename (without path).
 * @return void Exits program with EXIT_FAILURE on file access errors,
 * or continues validation through check_extension.
 */
void	check_map(char *str)
{
	int		fd;
	char	*path = "../fdf/maps/";
	char	*file = str;
	char	*finalpath;

	finalpath = ft_strjoin(path, file);
	fd = open(finalpath, O_RDONLY);
	if (fd == -1)
	{
		perror("Error open(): ");
		free(finalpath);
		exit(EXIT_FAILURE);
	}
	else
		check_extension(finalpath, fd);
	close(fd);
}
