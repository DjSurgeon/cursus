/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:14:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/09 11:35:20 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



t_screen2d	screen_position(int x, int y, t_sizemap *map)
{
	t_screen2d screen;
	
		// Funcion para calcular la escala automatica
	float	scale_x =  (float)WIDTH / (map->width);
	float	scale_y =  (float)HEIGHT / (map->height);
	float	scale = fmin(scale_x, scale_y) * 0.90;

		// Funcion para centrar
	int offset_x = (WIDTH - ((map->width - 1) * scale)) / 2;
	int offset_y = (HEIGHT - ((map->height -1) * scale)) / 2;

	screen.x_screen = offset_x + x * scale;
	screen.y_screen = offset_y + y * scale;
 	// int i = 0;
	 // while (i < map->height)
	// {
		// 	int j = 0;
		// 	while (j < map->width)
		// 	{
			// 		screen->x_screen = (map[i][j]->matrix.axis_x - 0.5) * (SCALE + WIDTH / 2);
			// 		screen->y_screen = (map[i][j]->matrix.axis_y - 0.5) * (SCALE + WIDTH / 2);
			// 		j++;
			// 	}
			// 	i++;
			// }
			//		screen->x_screen = (map->matrix[0][0].axis_x - 0.5) * (SCALE + WIDTH / 2);
			//		screen->y_screen = (map->matrix[0][1].axis_y - 0.5) * (SCALE + WIDTH / 2);
			
	return (screen);
}

/**
 * dibujar las 4 coordenadas
 */

void	draw_coordenates(t_data *data, t_sizemap *map)
{
	t_screen2d	screen;
	
	int i = 0;
	while (i < map->height)
	{
		int j = 0;
		while (j < map->width)
		{
			screen = screen_position(map->matrix[i][j].axis_x ,map->matrix[i][j].axis_y , map);
			put_pixel_to_image(data, screen.x_screen, screen.y_screen, map->matrix[i][j].color);
			j++;
		}
		i++;
	}
}