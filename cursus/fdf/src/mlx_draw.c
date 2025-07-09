/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:14:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/09 16:57:29 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* static t_screen2d	screen_2Dposition(int x, int y, t_sizemap *map)
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
 */
static t_screen3d	screen_3Dposition(float x, float y, float z, t_sizemap *map)
{
	t_screen3d screen;
	
		// Funcion para calcular la escala automatica
	float	scale_x =  (float)WIDTH / (map->width);
	float	scale_y =  (float)HEIGHT / (map->height);
	float	scale = fmin(scale_x, scale_y) * 0.90;

		// Funcion para centrar
	int offset_x = (WIDTH - ((map->width - 1) * scale)) / 2;
	int offset_y = (HEIGHT - ((map->height -1) * scale)) / 2;

	// isometrica

	float	iso_x = (x - y) * cos(0.5236);
	float	iso_y = (x + y) * sin(0.5236) - z; 

	screen.x_screen = offset_x + iso_x * scale;
	screen.y_screen = offset_y + iso_y * scale;
	return (screen);
}

/**
 * dibujar las 4 coordenadas
 */

/* void	draw_2Dcoordenates(t_data *data, t_sizemap *map)
{
	t_screen2d	screen;
	
	int i = 0;
	while (i < map->height)
	{
		int j = 0;
		while (j < map->width)
		{
			screen = screen_2Dposition(map->matrix[i][j].axis_x ,map->matrix[i][j].axis_y, map->matrix[i][j].axis_z, map);
			put_pixel_to_image(data, screen.x_screen, screen.y_screen, map->matrix[i][j].color);
			j++;
		}
		i++;
	}
} */

void	draw_3Dcoordenates(t_data *data, t_sizemap *map)
{
	t_screen3d	screen;
	int i = 0;
	while (i < map->height)
	{
		int j = 0;
		while (j < map->width)
		{
			screen = screen_3Dposition(map->matrix[i][j].axis_x ,map->matrix[i][j].axis_y, map->matrix[i][j].axis_z , map);
			put_pixel_to_image(data, screen.x_screen, screen.y_screen, map->matrix[i][j].color);
			j++;
		}
		i++;
	}
}