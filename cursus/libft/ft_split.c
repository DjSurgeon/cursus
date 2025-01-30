/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:05:05 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/30 11:09:20 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: separate a string in substring with delimiter char
**	parameters: the string an the character delimiter
**	result:	pointer to array of strings
*/

#include "libft.h"

int	assign_malloc(char **array, size_t position, size_t size)
{
	size_t	i;

	i = 0;
	array[position] = malloc(size);
	if (array[position] == NULL)
	{
		while (i < position)
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (1);
	}
	return (0);
}

int	ft_substr_cpy(char **substrings_array, char const *string, char c, size_t substrings)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (string[i] != '\0' && j < substrings)
	{
		len = 0;
		while (string[i] != '\0' && string[i] == c)
			i++;
		while (string[i] != '\0' && string[i] != c)
		{
			len++;
			i++;
		}
		if (len != 0)
		{
			if (assign_malloc(substrings_array, j, len + 1))
				return (1);
		}
		ft_strlcpy(substrings_array[j], &string[i - len], len + 1);
		j++;
	}
	return (0);
}

size_t	ft_count_strings(const char *string, char character)
{
	size_t	sub_strings;
	size_t	i;
	int		is_in_string;

	sub_strings = 0;
	i = 0;
	while (string[i] != '\0')
	{
		is_in_string = 0;
		while (string[i] != '\0' && string[i] == character)
		{
			i++;
		}
		while (string[i] != '\0' && string[i] != character)
		{
			if (is_in_string == 0)
			{
				sub_strings++;
				is_in_string = 1;
			}
			i++;
		}
	}
	return (sub_strings);
}

char	**ft_split(char const *s, char c)
{
	size_t	substrings;
	char	**substrings_array;

	if (s == NULL)
		return (NULL);
	substrings = ft_count_strings(s, c);
	substrings_array = ft_calloc(substrings, sizeof(char *));
	if (substrings_array == NULL)
		return (NULL);
	if (ft_substr_cpy(substrings_array, s, c, substrings) == 1)
		return (NULL);
	return (substrings_array);
}
