/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:08:13 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/28 17:28:10 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	offset = (y * data->img.line_len) + (x * (data->img.bits_per_pixel / 8));
	/*
	y * img->line_len - Salta Y líneas completas
	x * (img->bits_per_pixel / 8) - Avanza X píxeles en la línea actual
	*/
	// Dirección de memoria exacta del pixel que se va a pintar
	pixel = data->img.img_data + offset;
	// Color en esa posicion
	*(int *)pixel = color;
}
void	print_square(t_data *data, int axis_x, int axis_y, int length)
{
	int	i;
	int j;

	i = axis_x;
	j = axis_y;
	while (i - axis_x < length)
	{
		put_pixel_to_image(data, i, axis_y, 0xFF0000);
		put_pixel_to_image(data, i, axis_y + length, 0xFF0000);
		i++;
		while (j - axis_y < length)
		{
			put_pixel_to_image(data, axis_x, j, 0x00FF00);
			put_pixel_to_image(data, axis_x + length, j, 0x00FF00);
			j++;
		}
	}
}
void	print_rectangle(t_data *data, int axis_x, int axis_y, int witdh, int heigth)
{
	int	i;
	int j;

	i = axis_x;
	j = axis_y;
	while (i - axis_x < witdh)
	{
		put_pixel_to_image(data, i, axis_y, 0xFF0000);
		put_pixel_to_image(data, i, axis_y + heigth	, 0xFF0000);
		i++;
		while (j - axis_y < heigth)
		{
			put_pixel_to_image(data, axis_x, j, 0x00FF00);
			put_pixel_to_image(data, axis_x + witdh, j, 0x00FF00);
			j++;
		}
	}
}


void	one_pixel(int x, int y, int color)
{
	t_data	*one;
	(void)color;

	one = malloc(sizeof(t_data));
	if (!one)
		return ;
	one->width = WIDTH;
	one->height = HEIGHT;
	one->mlx_ptr = mlx_init();
	if (!one->mlx_ptr)
		return (perror("Conexion Fallida."));
	one->win_ptr = mlx_new_window(one->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!one->win_ptr)
		return (perror("Fallo en la creación de la ventana."));
	one->img.img_ptr = mlx_new_image(one->mlx_ptr, WIDTH, HEIGHT);
	if (!one->img.img_ptr)
		return (perror("Fallo al crear la imagen"));
	one->img.img_data = mlx_get_data_addr(one->img.img_ptr,
		&one->img.bits_per_pixel, &one->img.line_len, &one->img.endian);
	if (!one->img.img_data)
		return (perror("Fallo al obtener la memoria de la imagen"));
	//print_square(one, x, y, 200);
	print_rectangle(one, x, y, 100, 50);
	mlx_put_image_to_window(one->mlx_ptr, one->win_ptr, one->img.img_ptr, 0, 0);
	mlx_loop(one->mlx_ptr);
}
