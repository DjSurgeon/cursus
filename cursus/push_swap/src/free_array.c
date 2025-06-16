/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:09:37 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/16 17:34:29 by sergio-jime      ###   ########.fr       */
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
