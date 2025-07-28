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

/**
 * @file mlx_hooks.c
 * @brief Handles keyboard input events.
 * Processes key presses and executes corresponding actions:
 * - ESC (65307): Closes window and exits program.
 * @param keycode X11 keycode of pressed key.
 * @param data Pointer to main application data structure.
 * @return int 0 (event handled).
 * @warning Uses X11 keycode values (for linux systems).
 * @warning MacOS may use different keycodes.
 */
static int	key_press(int keycode, t_data *data)
{
	ft_printf("%d\n", keycode);
	if (keycode == 65307)
	{
		free_map(data->map, data->map->height);
		free_mlx(data);
		exit(EXIT_SUCCESS);
	}
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
