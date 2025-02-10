/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:22:07 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/10 12:22:47 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *buffer, char c)
{
	size_t	i;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destination_len;
	size_t	source_len;
	size_t	i;

	destination_len = ft_strlen(dst);
	source_len = ft_strlen(src);
	i = 0;
	if (size <= destination_len)
		return (size + source_len);
	while (src[i] && (destination_len + i < size - 1))
	{
		dst[destination_len + i] = src[i];
		i++;
	}
	dst[destination_len + i] = '\0';
	return (source_len + destination_len);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	j = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new_string = malloc(size_s1 + size_s2 + 1);
	if (!new_string)
		return (NULL);
	while (i < size_s1)
	{
		new_string[i] = s1[i];
		i++;
	}
	while (j < size_s2)
	{
		new_string[i + j] = s2 [j];
		j++;
	}
	new_string[i] = '\0';
	return (new_string);
}