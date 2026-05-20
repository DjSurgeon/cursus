/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:32:33 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/28 23:01:11 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file mlx_hooks.c
 * @brief Handles window close event (clicking X button).
 * Properly cleans up MLX resources and exits the program when the
 * user clicks the window close button.
 * @param data Pointer to main application data structure.
 * @return int 0 (event handled).
 * @warning Terminates program execution.
 */
static int	close_window(t_data *data)
{
	free_map(data->map, data->map->height);
	free_mlx(data);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	handle_translation(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->offset_x -= 10;
	else if (keycode == 65363)
		data->offset_x += 10;
	else if (keycode == 65362)
		data->offset_y -= 10;
	else if (keycode == 65364)
		data->offset_y += 10;
}

static void	handle_zoom(int keycode, t_data *data)
{
	if (keycode == 61 || keycode == 65451)
		data->zoom *= 1.1;
	else if (keycode == 45 || keycode == 65453)
	{
		data->zoom /= 1.1;
		if (data->zoom < 0.05)
			data->zoom = 0.05;
	}
}

static void	handle_rotation(int keycode, t_data *data)
{
	if (keycode == 119)
		data->angle_x += 0.05;
	else if (keycode == 115)
		data->angle_x -= 0.05;
	else if (keycode == 97)
		data->angle_y += 0.05;
	else if (keycode == 100)
		data->angle_y -= 0.05;
	else if (keycode == 113)
		data->angle_z += 0.05;
	else if (keycode == 101)
		data->angle_z -= 0.05;
}

static void	handle_z_scale(int keycode, t_data *data)
{
	if (keycode == 93)
		data->z_scale += 0.1;
	else if (keycode == 91)
		data->z_scale -= 0.1;
}

/**
 * @file mlx_hooks.c
 * @brief Clears the image buffer, draws the map, and puts the image to the window.
 * @param data Pointer to main application data structure.
 */
void	render_frame(t_data *data)
{
	ft_bzero(data->img->img_data, data->img->line_len * HEIGHT);
	draw(data, data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->img_ptr, 0, 0);
}

/**
 * @file mlx_hooks.c
 * @brief Handles keyboard input events.
 * Processes key presses and executes corresponding actions.
 * @param keycode X11 keycode of pressed key.
 * @param data Pointer to main application data structure.
 * @return int 0 (event handled).
 */
static int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65361 || keycode == 65363
		|| keycode == 65362 || keycode == 65364)
		handle_translation(keycode, data);
	else if (keycode == 61 || keycode == 65451
		|| keycode == 45 || keycode == 65453)
		handle_zoom(keycode, data);
	else if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100
		|| keycode == 113 || keycode == 101)
		handle_rotation(keycode, data);
	else if (keycode == 93 || keycode == 91)
		handle_z_scale(keycode, data);
	else if (keycode == 112)
		data->projection_mode = !data->projection_mode;
	render_frame(data);
	return (0);
}

/**
 * @file mlx_hooks.c
 * @brief Initializes all event hooks for FDF.
 * Sets up handlers for:
 * - Keyboard preses (KeyPress event).
 * - Window close button (ClientMessage event).
 * @note Uses MLX's event hook system.
 * @param data Pointer to main application data structure.
 * @return bool true If hooks were set succesfully.
 * @warning Must be called after window creation.
 */
bool	fdf_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 2, (1L << 0), key_press, data);
	mlx_hook(data->win_ptr, 17, (1L << 8), close_window, data);
	return (true);
}
