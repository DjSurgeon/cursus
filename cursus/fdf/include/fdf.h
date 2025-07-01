/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:25:45 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/01 19:03:18 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file fdf.h
 * @brief Main header for FDF project containing all structures and
 * function declarations.
 */
#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>

// Macros por defecto

# define WIDTH 800
# define HEIGHT 600
# define TITLE "FDF 42"

// Estructuras

typedef struct	s_coordinates
{
	int			axis_x;
	int			axis_y;
	int			axis_z;
	int			color;
}				t_coordinates;

typedef struct s_sizemap
{
	int			check_width;
	int			width;
	int			heigth;
	int			**matrix;
}				t_sizemap;


typedef struct	s_img {
	void	*img_ptr;			// Puntero a la imagen MLX
	// data->image->img_ptr = mlx_new_image(data->mlx_ptr, 800, 600);
	// Necesitamos saber de que puntero estamos hablando.
	char	*img_data;			// Datos raw de la imagen
	// image->img_data = mlx_get_data_addr(data->image->img_ptr,
	// &data->image->bits_per_pixel, &data->image->line_len,
	// &data->image->endian);
	// Este puntero es muy importante y que necesitamos saber la posicion
	// de la memoria donde estan alamacenado los colores de cada pixel.
	int		bits_per_pixel;		// Bits por píxel (generalmente 32)
	// 4 bytes por pixel
	int		line_len;			// Bytes por línea
	// El sistem operativo puede añadir bytes extras al final por razones de memoria
	int		endian;				// Orden de bytes
	// little-endian en sistemaa x86/x64
}				t_img;

typedef struct	s_data {
	void	*mlx_ptr;			// Puntero a la instancia MLX
	void	*win_ptr;			// Puntero a la ventana
	t_img	img;				// Estructura de imagen
	int		width;				// Ancho de la ventana
	int		height;				// Alto de la ventana
}				t_data;

// Test y ejercicios

// void	hello_mlx(void);
// void	draw_pixels(void);
// void	draw_square(int w, int h);
// void	close_with_esc(void);
// void	one_pixel(int x, int y, int color);
void	put_pixel_to_image(t_data *data, int x, int y, int color);
void	init_window(t_data **data, int width, int height, char* title);
void	init_image(t_data *data, int width, int height);
int		key_press_event(int keycode, t_data *data);
int		close_program(t_data *data);
int		mouse_press_event(int button, int x, int y, t_data *data);
void	print_rectangle(t_data *data, int axis_x, int axis_y, int witdh, int heigth);

// Modulo de parseo de datos

bool	check_map(char *str);
bool	check_file(char *finalpath, int fd);
void	create_coordinates(t_sizemap *map, int fd);

// Modulo de errores

void	print_error(char *str, char *path);

// liberacion de memoria

void	free_matrix(int **matrix);

#endif