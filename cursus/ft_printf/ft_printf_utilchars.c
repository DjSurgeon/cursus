/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilchars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:48:12 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/17 00:22:40 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}

int	ft_countstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return ((void *) destination);
}
