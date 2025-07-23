/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:20:40 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/23 14:29:08 by sergio-jime      ###   ########.fr       */
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

void	free_structure(t_coordinates **structure, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(structure[i]);
		i++;
	}
	free(structure);
}

void	free_map(t_sizemap *structure, int height)
{
	free_structure(structure->matrix, height);
	free(structure);
}