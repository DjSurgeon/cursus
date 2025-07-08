/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:47:50 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/08 18:10:47 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * buffer de imagen
 */

 void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	// Verificar que las coordenadas estan dentro de la imagen
	data->width = WIDTH;
	data->height = HEIGHT;
	// Valores positivos dentro de las coordenadas dadas.
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	// Calcular la posicion exacta en la memoria
	offset = (y * data->img.line_len) + (x * (data->img.bpp / 8));
	/*
	y * img->line_len - Salta Y líneas completas
	x * (img->bits_per_pixel / 8) - Avanza X píxeles en la línea actual
	*/
	// Dirección de memoria exacta del pixel que se va a pintar
	pixel = data->img.img_data + offset;
	// Color en esa posicion
	*(int *)pixel = color;
}

/**
 * 
 */
void	init_window(t_data *data, int width, int height, char* title)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (perror("Fallo conexion con MinilibX"), free(data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, title);
	if (!data->win_ptr)
		return (perror("Fallo en la creación de la ventana"), free(data));
}

/**
 * 
 */
void	init_image(t_data *data, int width, int height)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	if (!data->img.img_ptr)
		return (perror("Fallo en la creación de la imagen"));
	data->img.img_data = mlx_get_data_addr(data->img.img_ptr,
		&data->img.bpp, &data->img.line_len, &data->img.endian);
	if (!data->img.img_data)
		return (perror("Fallo en la recuperacion de los datos de la imagen"));
}

void	init_fdf(t_sizemap *map)
{
	t_data	*fdf_data;
	(void)map;
	
	fdf_data = malloc(sizeof(t_data));
	if (!fdf_data)
		return (perror("Fallo inicialización estructura."));
	init_window(fdf_data, WIDTH, HEIGHT, TITLE);
	init_image(fdf_data, WIDTH, HEIGHT);
	/**
	 * Eventos y dibujos
	 */
		// put_pixel_to_image(fdf_data, 400, 300, 0x00FF00);
	draw_coordenates(fdf_data, map);
	mlx_put_image_to_window(fdf_data->mlx_ptr, fdf_data->win_ptr, fdf_data->img.img_ptr, 0, 0);
	mlx_loop(fdf_data->mlx_ptr);
}
