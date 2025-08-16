/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:25:45 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/08/16 13:07:22 by sergio-jime      ###   ########.fr       */
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

/* -------------------------------- Macros ---------------------------------- */

/**
 * @brief Defaults parameters.
 */

# define WIDTH 1920
# define HEIGHT 1080
# define TITLE "serjimen - FDF 42"
# define SCALE 50

/* ------------------------------ Structures -------------------------------- */

/**
 * @struct s_bresenham
 * @brief Stores parameters for Bresenham's line algorithm.
 * @param diffx Difference in x coordinates.
 * @param diffy Difference in y coordinates.
 * @param stepx Step direction in x axis.
 * @param stepy Step direction in y axis.
 * @param varerr Error variable.
 * @param temperr Temporary error variable.
 */
typedef struct s_bresenham
{
	int	diffx;
	int	diffy;
	int	stepx;
	int	stepy;
	int	varerr;
	int	temperr;
}		t_bresenham;

/**
 * @struct s_scr2d
 * @brief Stores 2D screen coordinates.
 * @param x_screen X coordinate on screen.
 * @param y_screen Y coordinate on screen.
 * @param x_screen X coordinate on screen.
 * @param y_screen Y coordinate on screen.
 * @param scale_x Horizontal scaling factor projection.
 * @param scale_y Vertical scaling factor projection.
 * @param scale Uniform scaling projection.
 * @param offset_x Horizontal screen offset.
 * @param offset_y Vertical screen offset.
 */
typedef struct s_scr2d
{
	int		x_screen;
	int		y_screen;
	float	scale_x;
	float	scale_y;
	float	scale;
	int		offset_x;
	int		offset_y;
}		t_scr2d;

/**
 * @struct s_scr3d
 * @brief Stores 3D screen coordinates.
 * @param x_screen X coordinate on screen.
 * @param y_screen Y coordinate on screen.
 * @param scale_x Horizontal scaling factor projection.
 * @param scale_y Vertical scaling factor projection.
 * @param scale Uniform scaling projection.
 * @param offset_x Horizontal screen offset.
 * @param offset_y Vertical screen offset.
 * @param iso_x Intermediate isometric X value during calculation.
 * @param iso_y Intermediate isometric Y value during calculation.
 */
typedef struct s_scr3d
{
	int		x_screen;
	int		y_screen;
	float	scale_x;
	float	scale_y;
	float	scale;
	int		offset_x;
	int		offset_y;
	float	iso_x;
	float	iso_y;
}		t_scr3d;

/**
 * @struct s_coordinates
 * @brief Stores 3D world coordinates and color.
 * @param axis_x X coordinate in world space.
 * @param axis_y Y coordinate in world space.
 * @param axis_z Z coordinate in world space (height).
 * @param color Color value.
 */
typedef struct s_coordinates
{
	int	axis_x;
	int	axis_y;
	int	axis_z;
	int	color;
}		t_coordinates;

/**
 * @struct s_sizemap
 * @brief Stores map dimensions and coordinate matrix.
 * @param expected_with Expected width from first line.
 * @param width Actual map width.
 * @param height Map height.
 * @param matrix 2D array of coordinates.
 */
typedef struct s_sizemap
{
	int				expected_width;
	int				width;
	int				height;
	t_coordinates	**matrix;
}					t_sizemap;

/**
 * @struct s_img
 * @brief Stores MLX image data.
 * @param img_ptr Pointer to MLX image.
 * @param img_data Raw image data.
 * @param bpp Bits per pixel.
 * @param line_len Bytes per line.
 * @param endian Byte order.
 */
typedef struct s_img
{
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

/**
 * @struct s_data
 * @brief Main data structure for MLX operations.
 * @param mlx_ptr Pointer to MLX instance.
 * @param win_ptr Pointer to window.
 * @param img Pointer to image structure.
 * @param width Window width.
 * @param height Window height.
 * @param map Pointer to map data structure.
 */
typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	int			width;
	int			height;
	t_sizemap	*map;
}				t_data;

/* ---------------------------- MLX Module ---------------------------------- */

void		init_fdf(t_sizemap *map);
void		init_window(t_data *data, int width, int height, char *title);
void		init_image(t_data *data, int width, int height);
void		put_pixel_to_image(t_data *data, int x, int y, int color);
void		draw_3dcoordenates(t_data *data, t_sizemap *map);
t_scr3d		screen_3dposition(float x, float y, float z, t_sizemap *map);
void		bresenham(t_data *data, t_scr3d pstart, t_scr3d pend, int color);
void		draw(t_data *data, t_sizemap *map);

/* ----------------------- Map Parsing Module ------------------------------- */

t_sizemap	*check_map(char *str, t_sizemap *map);
t_sizemap	*validate_map(char *finalpath, int fd, t_sizemap *map);
t_sizemap	*create_coordinates(t_sizemap *map, int fd);
bool		validate_format(char *line, t_sizemap *map);

/* --------------------------- Utils Module --------------------------------- */

int			open_path(char *str);
bool		is_valid_number(char *str);
bool		is_valid_hexa(char *str);
bool		is_correct_width(t_sizemap *map);
t_sizemap	*create_sizemap(t_sizemap *map);

/* ------------------------- Error Handling Module -------------------------- */

void		print_error(char *str);

/* ---------------------- Memory Management Module -------------------------- */

void		free_matrix(char **matrix);
void		free_structure(t_coordinates **structure, int heght);
void		free_map(t_sizemap *structure, int height);
void		free_mlx(void *mlxdata);

/* ---------------------------- Hooks Module -------------------------------- */

bool		fdf_hooks(t_data *data);

/* ---------------------------- Debug Module -------------------------------- */

void		print_coord(t_sizemap	*fdf);

#endif
