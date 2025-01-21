/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:39:07 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/21 23:38:06 by sergio-jimene    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total_size;
	void			*memory_pointer;
	unsigned char	*clean_memory;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	i = 0;
	total_size = nmemb * size;
	memory_pointer = malloc(total_size);
	if (memory_pointer == NULL)
		return (NULL);
	clean_memory = (unsigned char *)memory_pointer;
	while (i < total_size)
	{
		clean_memory[i] = 0;
		i++;
	}
	return ((void *)clean_memory);
}
