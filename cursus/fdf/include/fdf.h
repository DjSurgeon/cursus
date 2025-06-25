/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:25:45 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/25 19:26:27 by sergio-jime      ###   ########.fr       */
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

// Test y ejercicios

void	hello_mlx(void);
void	draw_pixels(void);
void	draw_square(int w, int h);
void	close_with_esc(void);

#endif