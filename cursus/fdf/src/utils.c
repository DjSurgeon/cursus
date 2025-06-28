/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:28:23 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/28 18:28:34 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** **/

void	init_window(t_data **data, int width, int height, char* title)
{
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		return (perror("Fallo inicialización estructura."));
	(*data)->mlx_ptr = mlx_init();
	if (!(*data)->mlx_ptr)
		return (perror("Fallo conexion con MinilibX"), free((*data)));
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr, width, height, title);
	if (!(*data)->win_ptr)
		return (perror("Fallo en la creación de la ventana"), free((*data)));
	}

void	init_image(t_data *data, int width, int height)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	if (!data->img.img_ptr)
		return (perror("Fallo en la creación de la imagen"));
	data->img.img_data = mlx_get_data_addr(data->img.img_ptr,
		&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
	if (!data->img.img_data)
		return (perror("Fallo en la recuperacion de los datos de la imagen"));
}