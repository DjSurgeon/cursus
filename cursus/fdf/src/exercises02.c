/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:03:34 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/25 19:11:03 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(int	w, int h)
{
	t_data	*square;
	int		x;
	int		y;

	x = 0;
	y = 0;
	square = malloc(sizeof(t_data));
	if (!square)
		return ;
	square->mlx = mlx_init();
	square->window = mlx_new_window(square->mlx, 500, 500, "My square");
	square->image = mlx_new_image(square->mlx, 500, 500);
	square->addr = mlx_get_data_addr(square->image, &square->bits_per_pixel, &square->line_length, &square->endian);
	while (x < w)
	{
		my_mlx_pixel_put(square, x, w, 0xFF0000);
		my_mlx_pixel_put(square, y, x + h, 0xFF0000);
		x++;
	}
	while (y < h)
	{
		my_mlx_pixel_put(square, y, w + h, 0x00FF00);
		my_mlx_pixel_put(square, w, y + h, 0x00FF00);
		y++;
	}
	
	mlx_put_image_to_window(square->mlx, square->window, square->image, 25, 25);
	mlx_loop(square->mlx);
}
