/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:09:37 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/17 12:34:40 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Safely deallocates a dynamically allocated array of strings.
 * Frees:
 * - Individual string elements.
 * - The array container itself.
 * @param c_array Double pointer to the string array.
 * @note Handles NULL input correctly.
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
