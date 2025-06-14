/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:09:37 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/14 18:05:38 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Free the char array and all the elements.
 * @param c_array The array of chars.
 */
void	free_array_c(char **c_array)
{
	int	i;

	if (!c_array)
		return ;
	i = 0;
	while (c_array[i])
	{
		free(c_array[i]);
		i++;
	}
	free(c_array);
}

/**
 * @brief Free the char array and all the elements.
 * @param i_array The array of ints.
 */
void	free_array_i(int **i_array)
{
	int	i;

	if (!i_array)
		return ;
	i = 0;
	while (i_array[i])
	{
		free(i_array[i]);
		i++;
	}
	free(i_array);
}