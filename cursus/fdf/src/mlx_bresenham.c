/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:06:05 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/21 14:03:51 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * 
 */

void	draw_bresenham(t_data *data, t_screen3d pstart, t_screen3d pend, int color)
{
	t_bresenham	bresen;
	
	bresen.diffx = abs(pend.x_screen - pstart.x_screen);
	bresen.diffy = -abs(pend.y_screen - pstart.y_screen);
	if (pstart.x_screen < pend.x_screen)
		bresen.stepx = 1;
	else
		bresen.stepx = -1;
	if (pstart.y_screen < pend.y_screen)
		bresen.stepy = 1;
	else
		bresen.stepy = -1;
	bresen.varerr = bresen.diffx + bresen.diffy;

	int	x;
	int	y;
	x = pstart.x_screen;
	y = pstart.y_screen;
	while (1)
	{
		put_pixel_to_image(data, x, y, color);
		if (x == pend.x_screen && y == pend.y_screen)
			break ;
		bresen.temperr = 2 * bresen.varerr;
		if (bresen.temperr >= bresen.diffy)
		{
			bresen.varerr += bresen.diffy;
			x += bresen.stepx;
		}
		if (bresen.temperr <= bresen.diffx)
		{
			bresen.varerr += bresen.diffx;
			y += bresen.stepy;
		}
	}
}

void	draw(t_data *data, t_sizemap *map)
{
	for (int row = 0; row < map->height; row++)
	{
		for (int col = 0; col < map->width; col++)
		{
			t_coordinates	c0 = map->matrix[row][col];
			t_screen3d		p0 = screen_3Dposition(c0.axis_x, c0.axis_y, c0.axis_z, map);
			// Derecha
			if (col + 1 < map->width)
			{
				t_coordinates	c1 = map->matrix[row][col+1];
				t_screen3d		p1 = screen_3Dposition(c1.axis_x, c1.axis_y, c1.axis_z, map);
				draw_bresenham(data, p0, p1, c0.color);
			}
			// Abajo
			if (row + 1 < map->height)
			{
				t_coordinates	c1 = map->matrix[row+1][col];
				t_screen3d		p1 = screen_3Dposition(c1.axis_x, c1.axis_y, c1.axis_z, map);
				draw_bresenham(data, p0, p1, c0.color);
			}
		}
	}
}