/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:32:33 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/09 16:14:54 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * hooks
 */

#include "fdf.h"

// Función que se ejecuta cuando se cierra la ventana
static int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
}

static int	key_press(int keycode, t_data *data)
{
	ft_printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

bool	fdf_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 2, (1L<<0), key_press, data);
	mlx_hook(data->win_ptr, 17, (1L<<8), close_window, data); // Cierre en X
	return (true);	
}