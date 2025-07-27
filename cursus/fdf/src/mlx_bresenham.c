/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:06:05 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/27 15:55:25 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file mlx_bresenham.c
 * @brief Initializes Bresenham algorithm parameters.
 * Calculates and returns the initial Bresenham parameters:
 * - Coordinate differences (diffx, diffy).
 * - Step directions (stepx, stepy).
 * - Initial error term.
 * @note Computes absolute coordinate differences.
 * @note Determines step directions (1 or -1).
 * @param bresen Bresenham parameter structure to initialize
 * @param ps Starting point coordinates.
 * @param pe Ending point coordinates.
 * @return t_bresenham Fully initialized Bresenham parameters.
 */
static t_bresenham	bresenham_aux(t_bresenham bresen, t_scr3d ps, t_scr3d pe)
{
	bresen.diffx = abs(pe.x_screen - ps.x_screen);
	bresen.diffy = -abs(pe.y_screen - ps.y_screen);
	if (ps.x_screen < pe.x_screen)
		bresen.stepx = 1;
	else
		bresen.stepx = -1;
	if (ps.y_screen < pe.y_screen)
		bresen.stepy = 1;
	else
		bresen.stepy = -1;
	bresen.varerr = bresen.diffx + bresen.diffy;
	return (bresen);
}

/**
 * @file mlx_bresenham.c
 * @brief Draws a line between two points using Bresenham's algorithm.
 * Renders a straight line in the image buffer using an optimized
 * integer-only line drawing algorithm. Handles all octants.
 * @note Works for all line slopes and directions.
 * @param data Pointer to main application data structure.
 * @param pstart Starting point coordinates.
 * @param pend Ending point coordinates.
 * @param color Line color in 0xAARRGGB format.
 * @return void.
 * @see bresenham_aux()
 * @warning Coordinaates must be within image bounds.
 */
void	bresenham(t_data *data, t_scr3d pstart, t_scr3d pend, int color)
{
	t_bresenham	bresen;
	int			y;
	int			x;

	bresen = bresenham_aux(bresen, pstart, pend);
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

/**
 * @file mlx_bresenham.c
 * @brief Draws connecting lines for a single map coordinate.
 * For a given map coordinate, draws lines to:
 * - The next horizontal neighbor (if exits).
 * - The next vertical neighbor (if exits).
 * @note Performs 3D to 2D coordinate conversion.
 * @note Uses Bresenham's algorithm for a line drawing.
 * @note Only draws right and down connections to avoid duplicates.
 * @param data Pointer to main application data structure.
 * @param map Pointer to populated map structure.
 * @param row Current row index in map matrix.
 * @param col Current column index in map matrix.
 * @return void.
 */
static void	draw_aux(t_data *data, t_sizemap *map, int row, int col)
{
	t_coordinates	c0;
	t_scr3d			p0;
	t_coordinates	c1;
	t_scr3d			p1;

	c0 = map->matrix[row][col];
	p0 = screen_3dposition(c0.axis_x, c0.axis_y, c0.axis_z, map);
	if (col + 1 < map->width)
	{
		c1 = map->matrix[row][col + 1];
		p1 = screen_3dposition(c1.axis_x, c1.axis_y, c1.axis_z, map);
		bresenham(data, p0, p1, c0.color);
	}
	if (row + 1 < map->height)
	{
		c1 = map->matrix[row + 1][col];
		p1 = screen_3dposition(c1.axis_x, c1.axis_y, c1.axis_z, map);
		bresenham(data, p0, p1, c0.color);
	}
}

/**
 * @file mlx_bresenham.c
 * @brief Renders the complete wireframe map.
 * Iterates through all map coordinates and draws connecting line between
 * neighboring points to form the wireframe structure.
 * @note Processes the map row by row, left to right.
 * @param data Pointer to main application data structure.
 * @param map Pointer to populated map structure.
 * @return void.
 * @see draw_aux()
 * @warning Requires initialized MLX image buffer.
 * @warning Map structure must be fully populated.
 */
void	draw(t_data *data, t_sizemap *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			draw_aux(data, map, row, col);
			col++;
		}
		row++;
	}
}
