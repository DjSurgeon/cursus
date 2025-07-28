/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:05:18 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/28 12:43:51 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file mlx_utils.c
 * @brief Renders 3D map coordinates to 2D screen space.
 * Transforms and draws all points from the 3D map matrix to the 2D
 * image buffer by:
 * 1 - Converting each coordinate to 2D screen position.
 * 2 - Drawing each point as a single pixel.
 * 3 - Preserving the original color data.
 * @note Uses isometric projection.
 * @note Draws each point individually.
 * @param data Pointer to main application data structure.
 * @param map Pointer to populated map structure.
 * @return void.
 * @warning Requires initialized image buffer.
 */
void	draw_3dcoordenates(t_data *data, t_sizemap *map)
{
	t_scr3d	screen;
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			screen = screen_3dposition(map->matrix[i][j].axis_x,
					map->matrix[i][j].axis_y, map->matrix[i][j].axis_z, map);
			put_pixel_to_image(data, screen.x_screen,
				screen.y_screen, map->matrix[i][j].color);
			j++;
		}
		i++;
	}
}
