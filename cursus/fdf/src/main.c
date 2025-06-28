/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:34:42 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/28 18:28:57 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_data	*fdf;

	
	// hello_mlx();
	// draw_pixels();
	// draw_square(100, 100);
	// close_with_esc();
	//	one_pixel(100, 100, 0xFF0000);
	
	init_window(&fdf, WIDTH, HEIGHT, TITLE);
	init_image(fdf, WIDTH, HEIGHT);

	// mlx_hook(fdf->win_ptr, 02, (1L<<0), key_press_event, fdf);
	// mlx_hook(fdf->win_ptr, 17, (1L<<8), close_program, fdf);
	// mlx_hook(fdf->win_ptr, 04, (1L<<2), mouse_press_event, fdf);
	// mlx_loop(fdf->mlx_ptr);

	return (EXIT_SUCCESS);
}
