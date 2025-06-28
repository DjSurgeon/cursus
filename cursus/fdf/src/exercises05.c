/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises05.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:28:46 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/28 18:28:20 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_program(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	exit (EXIT_SUCCESS);
}

void	clean_image(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		put_pixel_to_image(data, i+x, j+y, 0xFFFFFF);
		while (j < 5)
		{
			put_pixel_to_image(data, i+x, j+y, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	move_pixel(t_data *data)
{
	int	i;
	int	j;
	
	i = round(rand() % WIDTH);
	j = round(rand() % HEIGHT);
	put_pixel_to_image(data, i, j, 0x00FF00);
}


int	key_press_event(int keycode, t_data *data)
{
	ft_printf("Tecla presionada: %d\n", keycode);
	if (keycode == 65307)
		close_program(data);
	if (keycode == 32)
	{
		move_pixel(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	}
	return (0);
}

int	mouse_press_event(int button, int x, int y, t_data *data)
{
	ft_printf("Click %d, Posición (%d, %d)\n", button, x, y);
	if (button == 1)
	{
		put_pixel_to_image(data, x, y, 0x0000FF);
		print_rectangle(data, x, y, 100, 50);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	}
	if (button == 3)
	{
		clean_image(data,x , y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	}
	return (0);
}