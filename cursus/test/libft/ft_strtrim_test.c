/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:24:51 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/30 22:57:45 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
// #include "libft.h"

size_t ft_strlen(const char *s);

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
size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}
static  char *verify_len(size_t start, size_t end, char *new_string)
{
    if (start > end)
    {
    new_string = malloc(1);
    if (!new_string)
        return (NULL);
    new_string[0] = '\0';
    return (new_string);
    }
    return (NULL);
}
static void ft_copy_string(char *dest, const char *src, size_t start, size_t len)
{
    size_t i;

    i = 0;
    while (i < len)
    {
        dest[i] = src[start + i];
        i++;
    }
    dest[i] = '\0';
}

static int ft_char_in_set(char c, const char *set)
{
    size_t i;

    i = 0;
    while (set[i] != '\0')
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char *ft_strtrim(const char *s1, const char *set)
{
    char *new_string;
    size_t start;
    size_t end;
    int new_string_len;

    start = 0;
    if (s1 == NULL || set == NULL)
        return (NULL);
    while (s1[start] != '\0' && ft_char_in_set(s1[start], set) == 1)
        start++;
    end = ft_strlen(s1);
    while (end > 0 && ft_char_in_set(s1[end - 1], set) == 1)
        end--;
/*     if (start > end)
        {
            new_string = malloc(1);
            if (!new_string)
                return (NULL);
            new_string[0] = '\0';
            return (new_string);
        } */
/*     new_string_len = end - start;
    new_string = (char *)malloc(new_string_len + 1);
    if (!new_string)
        return (NULL); */
/*     ft_copy_string(new_string, s1, start, new_string_len); */
    new_string = ft_substr(s1, start, (size_t)end - start);
    return (new_string);
}
int main(void)
{
    char const s1[] = "";
    // char const *s2 = "\t \t \n   \n\n\n\t";
    char const set[] = "";
    
    // char const *set2 = '\t';
    char *result;

    result = ft_strtrim(s1, set);
    if (result)
    {
        write(1, result, ft_strlen(result));
        write(1, "\n", 1);
        free(result);
    }

    // printf("%s", ft_strtrim(s2, set2));
    return (0);
}