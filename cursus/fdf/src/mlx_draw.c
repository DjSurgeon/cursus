/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:14:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/28 12:58:33 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file mlx_draw.c
 * @brief Project 3D world coordinates to 2D screen space with
 * isometric transformation.
 * Performs aa complete 3D to 2D projection pipeline:
 * 1 - Calculates scaling factors based on window and map dimensions.
 * 2 - Determines optimal uniform scale (40% of min scale).
 * 3 - Computes centering offsets.
 * 4 - Applies isometric trnasformation (30° angle).
 * 5 - Scales and positions the final screen coordinates.
 * @note Uses standard isometric projection (30° angle).
 * @note Maintains aspect radio with uniform scaling.
 * @note Magic number 0.5236 radians = 30°.
 * @param x World X coordinate (column index).
 * @param y World Y coordinate (row index).
 * @param z World Z coordinate (height value).
 * @param map Pointer to map structure containing dimensions.
 * @return t_scr3d Structure containing:
 * - Final screen coordinates.
 * - Intermediate calculate values.
 * - Scale and offset parameters.
 */
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
