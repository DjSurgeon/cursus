/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:46:06 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/03 18:27:35 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * read file para adjudicar valores
 */
static bool	read_coordinates(int fd, t_sizemap *map)
{
	char			*line;
	char			**axis_z;
	char			**color;
	int				col;
	int				row;

	line = NULL;
	row = 0;
	while (1)
	{
		col = 0;
		line = get_next_line(fd);
		if (line == NULL)
		{
			return (true);
		}
		axis_z = ft_split(line, 32);
		if (!axis_z)
			return (free(line), false);
		while (col < map->width)
		{
			color = ft_split(axis_z[col], ',');
			if (!color)
				return (free_matrix(axis_z), free(line), false);
			map->matrix[row][col].axis_z = ft_atoi(color[0]);
			if (!color[1])
				map->matrix[row][col].color = ft_atoi_base("FFFFFF", 16);
			else
				map->matrix[row][col].color = ft_atoi_base(color[1] + 2, 16);
			free_matrix(color);
			col++;
		}
		free(line);
		free_matrix(axis_z);
		row++;
	}
	return (true);
}

/**
 * reservar matriz 2d
 */
static bool	allocate_matrix(t_sizemap *map)
{
	int	row;

	row = 0;
	map->matrix = ft_calloc(map->height, sizeof(t_coordinates *));
	if (!map->matrix)
	{
		print_error("Error Memory Allocation");
		return (false);
	}
	while (row < map->height)
	{
		map->matrix[row] = ft_calloc(map->width, sizeof(t_coordinates));
		if (!map->matrix[row])
		{
			print_error("Error Memory Allocation");
			free_structure(map->matrix, map->height);
			map->matrix = NULL;
			return (false);
		}
		row++;
	}
	return (true);
}

/**
 * reserva matrix y adjudica los valores
 */
bool	create_coordinates(t_sizemap *map, int fd)
{
	if (!allocate_matrix(map))
		return (false);
	if (!read_coordinates(fd, map))
		return (free_structure(map->matrix, map->height), print_error("Error Coordinates\n"), false);
	close(fd);
	return (free_structure(map->matrix, map->height), true);
}
