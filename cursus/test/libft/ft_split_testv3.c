/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_testv3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:41:34 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/31 02:21:34 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_substring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		new_substring = malloc(1);
		if (!new_substring)
			return (NULL);
		new_substring[0] = '\0';
		return (new_substring);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new_substring = ft_calloc(1, len + 1);
	if (!new_substring)
		return (NULL);
	while (i < len)
	{
		new_substring[i] = s[start + i];
		i++;
	}
	return (new_substring);
}
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
	int 	is_in_word;

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
	words = count_words(s,c);
	result = ft_calloc(words + 1, sizeof(char *));
	if (!result)
		return (NULL);
	if (!fill_words(result, s, c, words))
		return (NULL);
	return (result);
}
int main(void)
{
	// char *s1 = " hola   que tal    vaaassss    lololo    lolaloe dfasd  455677!   3·$·\"  $                ";
	// char *s2 = "";
	char **v = ft_split("42  \t  67    \t jh", '\t');
	// char **v = ft_split(s1, 'x');
	int i = 0;
	while(v[i])
		printf("%s\n", v[i++]); // Imprimimos cada substring
	i = 0;
	while (v[i])
		free (v[i++]);
	free(v); // Liberamos el array principal
	return (0);
}