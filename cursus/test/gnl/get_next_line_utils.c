/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:17:02 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/03/11 13:46:14 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	Description: Calculates the length of a null-terminated string.
**	Parameters:
**		- s: A pointer to the string whose length is to be calculated.
**	Return:
**		- The number of characters in the string, excluding the null terminator.
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}
/*
**	Description: Duplicates a null-terminated string by allocating memory and
	copying its content.
**	Parameters:
**		- s: A pointer to the null-terminated string to be duplicated.
**	Return:
**		- A pointer to the newly allocated duplicate string.
**		- NULL if memory allocation fails.
*/

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen (s);
	duplicate = malloc (len + 1 * sizeof (char));
	if (!duplicate)
		return (NULL);
	while (i < len)
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
/*
**	Description: Concatenates two null-terminated strings into a newly
	allocated string.
**	Parameters:
**	- s1: A pointer to the first null-terminated string.
**	- s2: A pointer to the second null-terminated string.
**	Return:
**	- A pointer to the newly allocated string containing the concatenation
	of s1 and s2.
**	- NULL if memory allocation fails.
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_string;
	size_t	len_s1;
	size_t	len_s2;	
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_string = malloc(len_s1 + len_s2 + 1 * sizeof(char));
	if (!new_string)
		return (NULL);
	while (i < len_s1)
	{
		new_string[i] = s1[i];
		i++;
	}
	free((void *)s1);
	while (j < len_s2)
	{
		new_string[i + j] = s2[j];
		j++;
	}
	return (new_string[i + j] = '\0', new_string);
}
/*
**	Description: Locates the first occurrence of a character in a
	null-terminated string.
**	Parameters:
**	- s: A pointer to the null-terminated string to search in.
**	- c: The character to search for, passed as an int but treated
	as an unsigned char.
**	Return:
**	- A pointer to the first occurrence of the character in the string.
**	- A pointer to the null terminator if c is '\0'.
**	- NULL if the character is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr = s;

	while (*ptr != '\0')
	{
		if (*ptr == (unsigned char)c)
			return ((char *)ptr);
		ptr++;
	}
	if (c == '\0')
		return ((char *)ptr);
	return (NULL);
}

/*
**	Description: Creates a new substring from a given string,
	starting at a specified position.
**	Parameters:
**	- s: A pointer to the null-terminated source string.
**	- start: The starting index from which to extract the substring.
**	- len: The maximum length of the substring to extract.
**	Return:
**	- A pointer to the newly allocated substring.
**	- An empty string if start is beyond the string's length.
**	- NULL if s is NULL or if memory allocation fails.
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substring = malloc(1);
		if (!substring)
			return (NULL);
		return (substring[0] = '\0', substring);
	}
	if (len > s_len - start)
		len = s_len - start;
	substring = malloc(len + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring[i] = '\0', substring);
}
