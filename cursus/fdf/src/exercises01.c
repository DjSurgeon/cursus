/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:38:49 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/28 10:32:24 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Crea un programa hello_mlx.c que al ejecutarlo abra una ventana de 400×300 
píxeles con el título "Hola, MLX" y se quede abierta hasta que cierres 
la ventana manualmente (cruz) o pulses ESC.

Aprender mlx_init, mlx_new_window, mlx_loop.
Entender el bucle principal de eventos.

Antes de hacer nada con la MinilibX necesitamos el header <mlx.h> que esta incluido 
en el header fdf.h

La función mlx_init() nos devuelve un puntero (void *) el cual tiene la localización
de nuestra instancia de MLX.

Seguidamente necesitaremos crear una ventana con mlx_new_window(*mlx, w, h, *s) esta
función tambien retorna un puntero a la ventana que acabamos de crear.

Después habrá que llamar mlx_loop() para mantener la ventana abierta y a la espera
de eventos (hooks).
*/

/* typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	hello_mlx(void)
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	char*	title;
	int		color;

	w = 1920;
	h = 1080;
	title = "Hola, MLX";
	color = 0xFF0000;
	mlx = mlx_init();
	win = mlx_new_window(mlx, w, h, title);
	mlx_pixel_put(mlx, win, w/2, h/2, color);
	(void)win;
	mlx_loop(mlx);
}


static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_pixels(void)
{
	t_data	img;
	int		w;
	int		h;
	int		i;

	w = 1920;
	h = 1080;
	i = 10;
	img.mlx = mlx_init();
	if (!img.mlx)
		return ;
	img.win = mlx_new_window(img.mlx, w, h, "Hi 42!");
	if (!img.win)
		return ;
	img.img = mlx_new_image(img.mlx, w, h);
	if (!img.img)
		return ;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
		return ;
	while (i < 500)
	{
		my_mlx_pixel_put(&img, i, 540, 0x00FF00);
		i++;
	}
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
 */