/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:14:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/08/16 13:16:40 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file mlx_draw.c
 * @brief Performs 3D rotation around the X axis.
 * @param y Pointer to Y coordinate.
 * @param z Pointer to Z coordinate.
 * @param angle Rotation angle in radians.
 */
static void	rotate_x(double *y, double *z, double angle)
{
	double	prev_y;

	prev_y = *y;
	*y = prev_y * cos(angle) - *z * sin(angle);
	*z = prev_y * sin(angle) + *z * cos(angle);
}

/**
 * @file mlx_draw.c
 * @brief Performs 3D rotation around the Y axis.
 * @param x Pointer to X coordinate.
 * @param z Pointer to Z coordinate.
 * @param angle Rotation angle in radians.
 */
static void	rotate_y(double *x, double *z, double angle)
{
	double	prev_x;

	prev_x = *x;
	*x = prev_x * cos(angle) + *z * sin(angle);
	*z = -prev_x * sin(angle) + *z * cos(angle);
}

/**
 * @file mlx_draw.c
 * @brief Performs 3D rotation around the Z axis.
 * @param x Pointer to X coordinate.
 * @param y Pointer to Y coordinate.
 * @param angle Rotation angle in radians.
 */
static void	rotate_z(double *x, double *y, double angle)
{
	double	prev_x;

	prev_x = *x;
	*x = prev_x * cos(angle) - *y * sin(angle);
	*y = prev_x * sin(angle) + *y * cos(angle);
}

/**
 * @file mlx_draw.c
 * @brief Project 3D world coordinates to 2D screen space with
 * rotation, scaling, offsets, and projection selection.
 * Performs a complete 3D to 2D projection pipeline:
 * 1 - Offsets coordinate to center of map.
 * 2 - Applies elevation scaling.
 * 3 - Performs 3D rotations on X, Y, Z axes.
 * 4 - Applies either Isometric (30° visual angle) or Parallel projection.
 * 5 - Scales and translates coordinates according to zoom and offsets.
 * @param x World X coordinate (column index).
 * @param y World Y coordinate (row index).
 * @param z World Z coordinate (height value).
 * @param data Pointer to main application data structure.
 * @return t_scr3d Structure containing final screen coordinates.
 */
t_scr3d	screen_3dposition(float x, float y, float z, t_data *data)
{
	t_scr3d	screen;
	double	rx;
	double	ry;
	double	rz;
	double	scale;

	rx = x - (double)(data->map->width - 1) / 2.0;
	ry = y - (double)(data->map->height - 1) / 2.0;
	rz = z * data->z_scale;
	rotate_x(&ry, &rz, data->angle_x);
	rotate_y(&rx, &rz, data->angle_y);
	rotate_z(&rx, &ry, data->angle_z);
	screen.iso_x = rx;
	screen.iso_y = ry;
	if (data->projection_mode == 0)
	{
		screen.iso_x = (rx - ry) * cos(0.5236);
		screen.iso_y = (rx + ry) * sin(0.5236) - rz;
	}
	scale = fmin((double)WIDTH / data->map->width,
			(double)HEIGHT / data->map->height) * 0.40 * data->zoom;
	screen.x_screen = (WIDTH / 2) + (int)(screen.iso_x * scale) + data->offset_x;
	screen.y_screen = (HEIGHT / 2) + (int)(screen.iso_y * scale) + data->offset_y;
	return (screen);
}
