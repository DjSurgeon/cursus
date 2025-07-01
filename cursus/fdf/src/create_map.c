/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:46:06 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/01 19:22:20 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * read file para adjudicar valores
 */
static bool	read_file_2(int fd, t_sizemap *map)
{
	char	*line;
	char	**axis_z;
	int		i;
	static int	j = 0;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			//free(map);
			return (true);
		}
		axis_z = ft_split(line, 32);
		i = 0;
		while (axis_z[i])
		{
			map->matrix[j][i] = ft_atoi(axis_z[i]);
			free(axis_z[i]);
			i++;
		}
		free(axis_z);
		j++;
		free(line);
	}
	return (true);
}

/**
 * reserva matrix y adjudica los valores
 */
void	create_coordinates(t_sizemap *map, int fd)
{
	int	col;

	col = 0;
	map->matrix = ft_calloc(map->heigth+1, sizeof(int *));
	while (col < map->heigth)
	{
		map->matrix[col] =  ft_calloc(map->width, sizeof(int));
		col++;
	}
	if (!read_file_2(fd, map))
		ft_printf("Error");
	close(fd);
	ft_printf("Col %d Row %d\n", map->width, map->heigth);
	col = 0;
	while (col < map->heigth)
	{
		int	row = 0;
		while (row < map->width)
		{
			if (row == 0)
				ft_printf("\n");
			ft_printf("%d ", map->matrix[col][row]);
			row++;
		}
		col++;
	}
	free_matrix(map->matrix);
}
