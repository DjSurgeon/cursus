/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:14:58 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/08 08:15:19 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * dibujar las 4 coordenadas
 */

void	draw_coordenates(t_screen2d *screen, t_data *data, t_sizemap *map)
{
	int i = 0;
	while (i < map->height)
	{
		int j = 0;
		while (j < map->width)
		{
			put_pixel_to_image(data, screen->x_screen, screen->y_screen, 0x00FF00);
			j++;
		}
		i++;
	}
}



t_screen2d	*screen_position(int x, int y, t_sizemap *map)
{
	t_screen2d	*screen;
	
	screen = NULL;
	screen = ft_calloc(1, sizeof(t_screen2d));
	if (!screen)
		return (NULL);
		// Funcion para calcular la escala automatica
	float	scale_x =  (float)WIDTH / (map->width + 1);
	float	scale_y =  (float)HEIGHT / (map->height + 1);
	float	scale = fmin(scale_x, scale_y) * 0. 85;

		// Funcion para centrar
	int offset_x = (WIDTH - (map->width * scale)) / 2;
	int offset_y = (HEIGHT - (map->height * scale)) / 2;

	screen->x_screen = offset_x + x * scale;
	screen->y_screen = offset_y + y * scale;
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