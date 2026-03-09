/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:39:07 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/28 13:12:48 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each 
 * and returns a pointer to the allocated memory.
 *
 * The memory is set to zero. If nmemb or size is 0, it returns a unique 
 * pointer value that can later be successfully passed to free().
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total_size;
	void			*memory_pointer;
	unsigned char	*clean_memory;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	memory_pointer = malloc(total_size);
	if (!memory_pointer)
		return (NULL);
	clean_memory = (unsigned char *)memory_pointer;
	i = 0;
	while (i < total_size)
	{
		clean_memory[i] = 0;
		i++;
	}
	return (clean_memory);
}
