/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:25:45 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/08 18:15:20 by sergio-jime      ###   ########.fr       */
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
# define TITLE "serjimen - FDF 42"
# define SCALE 150

// Estructuras

typedef struct s_screen2d
{
	int		x_screen;
	int		y_screen;
}			t_screen2d;

typedef struct	s_coordinates
{
	int			axis_x;
	int			axis_y;
	int			axis_z;
	int			color;
}				t_coordinates;

typedef struct s_sizemap
{
	int						expected_width;
	int						width;
	int						height;
	t_coordinates			**matrix;
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
	int		bpp;		// Bits por píxel (generalmente 32)
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
int		key_press_event(int keycode, t_data *data);
int		close_program(t_data *data);
int		mouse_press_event(int button, int x, int y, t_data *data);
void	print_rectangle(t_data *data, int axis_x, int axis_y, int witdh, int heigth);

// Modulo mlx
void	init_fdf(t_sizemap *map);
void	init_window(t_data *data, int width, int height, char* title);
void	init_image(t_data *data, int width, int height);
void	put_pixel_to_image(t_data *data, int x, int y, int color);
void	draw_coordenates(t_data *data, t_sizemap *map);
t_screen2d	screen_position(int x, int y, t_sizemap *map);

// Modulo de parseo de datos

t_sizemap	*check_map(char *str, t_sizemap *map);
t_sizemap	*validate_map(char *finalpath, int fd, t_sizemap *map);
t_sizemap	*create_coordinates(t_sizemap *map, int fd);
bool		validate_format(char *line, t_sizemap *map);

// Modulo utils

int			open_path(char *str);
bool		is_valid_number(char *str);
bool		is_valid_hexa(char *str);
bool		is_correct_width(t_sizemap *map);
t_sizemap	*create_sizemap(t_sizemap *map);

// Modulo de errores

void	print_error(char *str);

// liberacion de memoria

void	free_matrix(char **matrix);
void	free_structure(t_coordinates **structure, int heght);
void	free_map(t_sizemap *structure, int height);

// Debug

void print_coord(t_sizemap	*fdf);

#endif