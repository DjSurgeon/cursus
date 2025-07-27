/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:00:22 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/27 15:40:21 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_coord(t_sizemap	*fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("Map dimension Width: %d Height: %d\n",
				fdf->width, fdf->height);
			ft_printf("Axis x: %d\n", fdf->matrix[i][j].axis_x);
			ft_printf("Axis y: %d\n", fdf->matrix[i][j].axis_y);
			ft_printf("Axis z: %d\n", fdf->matrix[i][j].axis_z);
			ft_printf("Color: %d\n", fdf->matrix[i][j].color);
			j++;
		}
		i++;
	}
}
