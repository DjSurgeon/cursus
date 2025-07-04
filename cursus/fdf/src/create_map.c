/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:46:06 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/04 14:29:14 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * setear las coordenadas
 */
static t_sizemap	*set_coordinates(t_sizemap *map, char *line, int row)
{
	char	**axis_z;
	char	**color;
	int		col;

	col = 0;
	axis_z = ft_split(line, 32);
	if (!axis_z)
		return (free(line), NULL);
	while (col < map->width)
	{
		color = ft_split(axis_z[col], ',');
		if (!color)
			return (free_matrix(axis_z), free(line), NULL);
		map->matrix[row][col].axis_x = col;
		map->matrix[row][col].axis_y = row;
		map->matrix[row][col].axis_z = ft_atoi(color[0]);
		if (!color[1])
			map->matrix[row][col].color = ft_atoi_base("FFFFFF", 16);
		else
			map->matrix[row][col].color = ft_atoi_base(color[1] + 2, 16);
		free_matrix(color);
		col++;
	}
	free_matrix(axis_z);
	return (map);
}
/**
 * read file para adjudicar valores
 */
static t_sizemap	*read_coordinates(int fd, t_sizemap *map)
{
	char			*line;
	int				row;

	line = NULL;
	row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			return (map);
		}
		if (!set_coordinates(map, line, row))
			return (false);
		free(line);
		row++;
	}
	return (map);
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
t_sizemap	*create_coordinates(t_sizemap *map, int fd)
{
	if (!allocate_matrix(map))
		return (NULL);
	map = read_coordinates(fd, map);
	if (!read_coordinates(fd, map))
		return (free_structure(map->matrix, map->height), print_error("Error Coordinates\n"), NULL);
	close(fd);
	return (map);
}
