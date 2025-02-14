/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:53:37 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/31 02:27:13 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **array, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	fill_words(char **array, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words)
	{
		word_len = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			word_len++;
			i++;
		}
		if (word_len > 0)
			array[j] = ft_substr(s, i - word_len, word_len);
		if (!array[j])
			return (ft_free(array, j), 0);
		j++;
	}
	array[j] = NULL;
	return (1);
}

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;
	int		is_in_word;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		is_in_word = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (is_in_word == 0)
			{
				words++;
				is_in_word = 1;
			}
			i++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = ft_calloc(words + 1, sizeof(char *));
	if (!result)
		return (NULL);
	if (!fill_words(result, s, c, words))
		return (NULL);
	return (result);
}
