/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:12:06 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/22 13:44:21 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	chunk_count(char const *s, char c)
{
	size_t	count;
	size_t	chunk;

	count = 0;
	chunk = 0;
	while (*s)
	{
		if (*s == c)
			chunk = 0;
		else if (!chunk)
		{
			chunk = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static void	get_chunk(char **chnks, size_t cnt, const char *strt, size_t len)
{
	chnks[cnt] = malloc(len +1);
	ft_strlcpy(chnks[cnt], strt, len +1);
}

static size_t	find_chunks(char **chunks, char const *s, char c, size_t t_cnts)
{
	size_t	count;
	size_t	start;
	size_t	end;

	count = 0;
	start = 0;
	end = 0;
	while (s[end] && count < t_cnts)
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (s[start] != s[end])
		{
			get_chunk(chunks, count, &s[start], end - start);
			if (!chunks[count])
				return (0);
			count++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**chunks;
	size_t	counts;
	size_t	i;

	if (!s)
		return (NULL);
	counts = chunk_count(s, c);
	chunks = NULL;
	chunks = malloc((counts + 1) * sizeof(char *));
	if (!chunks)
		return (NULL);
	chunks[counts] = NULL;
	if (!find_chunks(chunks, s, c, counts))
	{
		i = 0;
		while (chunks[i])
		{
			free(chunks[i]);
			i++;
		}
		free(chunks);
		return (NULL);
	}
	return (chunks);
}
