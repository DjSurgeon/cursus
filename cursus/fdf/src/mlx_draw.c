/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:14:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/27 17:13:03 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_scr2d	screen_2dposition(t_sizemap *map)
{
	t_scr2d	screen;
	int		i;
	int		j;

	screen.scale_x = (float)WIDTH / (map->width);
	screen.scale_y = (float)HEIGHT / (map->height);
	screen.scale = fmin(screen.scale_x, screen.scale_y) * 0.40;
	screen.offset_x = (WIDTH - ((map->width - 1) * screen.scale)) / 2;
	screen.offset_y = (HEIGHT - ((map->height -1) * screen.scale)) / 2;
	screen.x_screen = screen.offset_x * screen.scale;
	screen.y_screen = screen.offset_y * screen.scale;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			screen.x_screen = (map[i][j]->matrix.axis_x - 0.5) * (SCALE + WIDTH / 2);
			screen.y_screen = (map[i][j]->matrix.axis_y - 0.5) * (SCALE + WIDTH / 2);
			j++;
		}
		i++;
	}
	return (screen);
}

t_scr3d	screen_3dposition(float x, float y, float z, t_sizemap *map)
{
	t_scr3d	screen;

	screen.scale_x = (float)WIDTH / (map->width);
	screen.scale_y = (float)HEIGHT / (map->height);
	screen.scale = fmin(screen.scale_x, screen.scale_y) * 0.40;
	screen.offset_x = (WIDTH - ((map->width - 1) * screen.scale)) / 2;
	screen.offset_y = (HEIGHT - ((map->height -1) * screen.scale)) / 2;
	screen.iso_x = (x - y) * cos(0.5236);
	screen.iso_y = (x + y) * sin(0.5236) - z;
	screen.x_screen = screen.offset_x + screen.iso_x * screen.scale;
	screen.y_screen = screen.offset_y + screen.iso_y * screen.scale;
	return (screen);
}
