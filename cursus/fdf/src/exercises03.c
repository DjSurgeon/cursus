/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:16:45 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/28 17:37:45 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/* 
typedef struct s_data {
    void 		*mlx_ptr;      // Puntero a la instancia MLX
    void 		*win_ptr;      // Puntero a la ventana
} 				t_data;

// Función que se ejecuta cuando se presiona ESC
static int key_press(int keycode, t_data *data)
{
	ft_printf("Tecla presionada: %d\n", keycode);
    if (keycode == 65307) // Código de ESC en Linux
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    return (0);
}

// Función que se ejecuta cuando se cierra la ventana
static int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
}

void	close_with_esc(void)
{
    t_data *window;
	int		w;
	int		l;

	w = 600;
	l = 600;
	// TODO: Inicializar MLX
	window = malloc(sizeof(t_data));
	if (!window)
		return ;
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		return ;
	ft_printf("Conexion inicializada\n");
    // TODO: Crear ventana
	window->win_ptr = mlx_new_window(window->mlx_ptr, w, l, "Hooks");
	if (!window->win_ptr)
		return ;
	ft_printf("Abriendo ventana de %d x %d\n", w, l);
    // TODO: Configurar eventos
//	mlx_key_hook(window->win_ptr, key_press, window);
	mlx_hook(window->win_ptr, 2, (1L<<0), key_press, window); // Tecla ESC
	mlx_hook(window->win_ptr, 17, (1L<<8), close_window, window); // Cierre en X
	// TODO: Iniciar loop principal
    mlx_loop(window->mlx_ptr);
}
 */