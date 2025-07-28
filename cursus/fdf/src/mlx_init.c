/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:47:50 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/28 18:47:26 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file mlx_init.c
 * @brief Set a pixel-level drawing operations.
 * Safely modifies a speceific pixel in the MLX image buffer by:
 * - Validating coordinates against image boundaries.
 * - Calculating the exact memory position.
 * - Writing the color value in proper format.
 * @note Uses image propierties from data->img structure:
 * - line_len: Bytes per image line.
 * - bpp: Bits per pixel.
 * - img_data: Raaw pixel buffer.
 * @param data Pointer to main application data structure.
 * @param x Horizontal coordinate.
 * @param y Vertical coordinate.
 * @param color Color value in 0xAARRGGBB format.
 * @return void.
 * @warning No effect if coordinates are out of bounds.
 */
void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	data->width = WIDTH;
	data->height = HEIGHT;
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	offset = (y * data->img->line_len) + (x * (data->img->bpp / 8));
	pixel = data->img->img_data + offset;
	*(int *)pixel = color;
}

/**
 * @file mlx_init.c
 * @brief Initializes an MLX image buffer for rendering.
 * Creates and configures an image abufer for the FDF visualization:
 * - Allocates a new MLX image with specified dimensions.
 * - Retrieves the image's memory address and properties.
 * - Sets up the image structure in the data parameter.
 * @note Stores image properties in data->img structure:
 * - img_ptr: MLX image pointer:
 * - img_data: Raw pixel data buffer.
 * - bpp: Bits per pixel.
 * - line_len: Bytes per image line.
 * - endian: System endianness.
 * @param data Pointer to main application data structure.
 * @param width Desired image width in pixels.
 * @param height Desired image height in pixels.
 * @return void.
 * @warning Image dimensions must be positive values.
 */
void	init_image(t_data *data, int width, int height)
{
	data->img = ft_calloc(1, sizeof(t_img));
	if (!data->img)
		return (print_error("Error: Failed to allocate structure image\n"),
			free_mlx(data));
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	if (!data->img->img_ptr)
		return (print_error("Error: Failed to create MLX image\n"),
			free_mlx(data));
	data->img->img_data = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bpp, &data->img->line_len, &data->img->endian);
	if (!data->img->img_data)
		return (print_error("Error: Failed to get image data address\n"),
			free_mlx(data));
}

/**
 * @file mlx_init.c
 * @brief Initializes MLX connection and creates application window.
 * Establishes the foundation for graphical display by:
 * 1 - Initializing the MLX graphics connection.
 * 2 - Creating a window with specified dimensions and title.
 * 3 - Handling initialization failures with proper cleanup.
 * @note Stores MLX pointers in daata structure:
 * - mlx_ptr: MLX connection pointer.
 * - win_ptr: Window pointer.
 * @param data Pointer to main application data structure.
 * @param width Window width in pixels.
 * @param height Window height in pixels.
 * @param title Window title string.
 * @return void.
 * @warning Terminates execution if MLX initialization fails.
 * @warning Window dimensions must be positive values.
 * @warning Title string must be valid (non-NULL).
 */
void	init_window(t_data *data, int width, int height, char *title)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (print_error("Error: Failed to initialize MLX connection\n"),
			free_mlx(data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, title);
	if (!data->win_ptr)
		return (print_error("Error: Failed to create MLX window"),
			free_mlx(data));
}

/**
 * @file mlx.init.c
 * @brief Initializes and runs the FDF visualization.
 * Sets up the complete FDF enviroment including:
 * - Main application data structure.
 * - MLX window and image buffers.
 * - Map rendering.
 * - Event hooks and main loop.
 * @note Performs complete initialization sequence:
 * 1 - Allocates main data structure.
 * 2 - Initializes MLX window.
 * 3 - Creates image buffer.
 * 4 - Renders the map.
 * 5 - Sets up event hooks.
 * 6 - Starts the MLX event loop.
 * @note Prints error messages to stderr on initialization failures.
 * @param map Pointer to fully populated t_sizempa structure.
 * @return void.
 * @warning The map structure must be fully populated.
 * @warning Teminates program on allocation failure.
 * @warning Enters inifinite loop.
 */
void	init_fdf(t_sizemap *map)
{
	t_data	*fdf_data;

	fdf_data = ft_calloc(1, sizeof(t_data));
	if (!fdf_data)
		return (print_error("Error: Failed to allocate FDF structure\n"));
	init_window(fdf_data, WIDTH, HEIGHT, TITLE);
	init_image(fdf_data, WIDTH, HEIGHT);
	draw(fdf_data, map);
	mlx_put_image_to_window(fdf_data->mlx_ptr, fdf_data->win_ptr,
		fdf_data->img->img_ptr, 0, 0);
	fdf_hooks(fdf_data);
	mlx_loop(fdf_data->mlx_ptr);
	free(fdf_data);
	free_map(map, HEIGHT);
}
