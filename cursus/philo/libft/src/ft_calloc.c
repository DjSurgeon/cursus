/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:39:07 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/23 17:05:35 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 * @brief Allocates and zero-initializes memory for an array.
 * This function allocates memory for an array of 'nmeb' elements, each size
 * 'size' bytes, and initializes all bytes to zero. It provides protection
 * against size_t overflow by returning NULL if the multiplication of nmeb
 * and size would overflow.
 * @note The memory is set to zero using byte-by-byte initialization.
 * @note If either nmeb or size is 0, returns a unique pointer that can
 * be freed.
 * @note The returned pointer should be freed when no longer needed.
 * @param nmeb Number of elements to allocate.
 * @param size Size of each element in bytes.
 * @return void* Pointer to the allocated memory, or NULL if allocation
 * fails or if nmeb * size overflow.
 * @code
 * // Example
 * int *arr = (int *)ft_calloc(10, sizeof(int));
 * if (!arr)
 * {
 *	// Handle allocation error
 * }
 * @endcode
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
