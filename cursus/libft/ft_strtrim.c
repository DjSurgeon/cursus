/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:11:14 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 14:57:24 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  description: delete all set characters in the string s
**  parameters: the string and the chars
**  return: the new string without set characters
*/

#include "libft.h"

static void	ft_copy_string(char *dest, const char *s, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_char_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new_string;
	size_t	start;
	size_t	end;
	int		new_string_len;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] != '\0' && ft_char_in_set(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_char_in_set(s1[end - 1], set) == 1)
		end--;
	new_string_len = end - start;
	new_string = (char *)malloc(new_string_len + 1);
	if (!new_string)
		return (NULL);
	ft_copy_string(new_string, s1, start, new_string_len);
	return (new_string);
}
