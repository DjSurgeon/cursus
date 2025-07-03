/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:46:06 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/03 14:47:16 by sergio-jime      ###   ########.fr       */
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
	int				i;
	int				x;

	line = NULL;
	x = 0;
	while (1)
	{
		i = 0;
		line = get_next_line(fd);
		if (line == NULL)
		{
			return (true);
		}
		axis_z = ft_split(line, 32);
		while (axis_z[i])
		{
			color = ft_split(axis_z[i], ',');
			map->matrix[i][0].axis_z = ft_atoi(color[0]);
			if (color[1])
				map->matrix[i][1].color = ft_atoi_base(color[1] + 2, 16);
			ft_printf("x = %d y = %d z = %d color = %d\n", x, i, map->matrix[i][0].axis_z, map->matrix[i][1].color);
			i++;
		}
		free(line);
		x++;
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
	map->matrix = ft_calloc(map->height, sizeof(int *));
	while (row < map->height)
	{
		map->matrix[row] = ft_calloc(map->width, sizeof(int));
		if (!map->matrix[row])
		{
			print_error("Error Memory Allocation");
			free_structure(map->matrix);
			return (false);
		}
		row++;
	}
	if (!map->matrix)
	{
		print_error("Error Memory Allocation");
		free_structure(map->matrix);
		return (false);
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
		return (ft_printf("Error"), false);
	close(fd);
	return (true);
}
