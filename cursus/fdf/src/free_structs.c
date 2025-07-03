/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:20:40 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/03 18:25:38 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Safely deallocates a dynamically allocated string array.
 * Iterates trough a NULL-terminated array of strings, freeing each
 * individual string and finally freeing the array pointer itself.
 * Handles NULL input gracefully (no operation).
 * @param matrix NULL-terminated array of strings to deallocate.
 * @return void.
 */
void	free_matrix(char **matrix)
{
	int	i;

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
