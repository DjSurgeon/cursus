/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:14:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/04 18:19:26 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * dibujar las 4 coordenadas
 */

void	draw_coordenates(t_sizemap *map, t_data *data)
{
	int i = 0;
	while (i < map->height)
	{
		int j = 0;
		while (j < map->width)
		{
			put_pixel_to_image(data, map->matrix[i][j].axis_x, map->matrix[i][j].axis_y, 0x00FF00);
			j++;
		}
		i++;
	}
}