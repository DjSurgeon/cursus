/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:20:40 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/28 18:30:48 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file free_structs.c
 * @brief Deallocates a NULL-terminated array of strings.
 * Safely releases memory  for:
 * - Each individual string in the array.
 * - The array pointer itself.
 * @note Handles NULL input gracefullly.
 * @note Works with partially populated arrays.
 * @param matrix NULL-terminated array of strings to deallocate.
 * @return void.
 * @warning Array must be properly NULL-terminated.
 */
void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

/**
 * @file free_structs.c
 * @brief Deallocates a 2D array of coordinate structures.
 * Safely releases memory for a height x N matrix of t_coordinates,
 * including all row arrays and the structure pointer itself.
 * @note Handles NULL input gracefully.
 * @note Frees memory in reverse allocation order (row first, the structure).
 * @param structure Pointer to the 2D coordinate array to free.
 * @param height Number of rows in the coordinate array.
 * @return void.
 * @warning Does not set the structure pointer to NULL after freeing.
 */
void	free_structure(t_coordinates **structure, int height)
{
	int	i;

	i = 0;
	if (!structure)
		return ;
	while (i < height)
	{
		free(structure[i]);
		i++;
	}
	free(structure);
}

/**
 * @file free_structs.c
 * @brief Deallocates an entire map structure and it contents.
 * Safely releases all memory associated with a t_sizemap structure, including
 * its coordinate matrix and structure itself.
 * @note Performs complete cleanup in proper order:
 * 1 - Coordinate matrix.
 * 2 - Map structure itself.
 * @param structure Pointer to the map structure to free.
 * @param height Number of rows in the coordinate matrix.
 * @return void.
 */
void	free_map(t_sizemap *structure, int height)
{
	if (!structure)
		return ;
	free_structure(structure->matrix, height);
	free(structure);
}

/**
 * 
 */
void	free_mlx(void *mlxdata)
{
	t_data	*data;
	
	data = (t_data *)mlxdata;
	if (data->img->img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
		free(data->img);
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr,data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data);
}