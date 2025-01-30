/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:59:49 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/30 23:34:20 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
		return (c);
	}
	return (c);
}
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		return (c);
	}
	return (c);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	
	i = 0;
	len = ft_strlen(s);
	if (c == '\0')
	{
		return ((char *)&s[len]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len]);
	while (len >= 0)
	{
		if (s[len] == c)
			return((char *)&s[len]);
		len--;		
	}
	return (NULL);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*byte1;
	unsigned char	*byte2;
	size_t			i;

	byte1 = (unsigned char *) s1;
	byte2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (byte1[i] != '\0' || byte2[i] != '\0'))
	{
		if (byte1[i] != byte2[i])
			return (byte1[i] - byte2[i]);
		i++;
	}
	return (0);
}
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
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
char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new_string;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && ft_char_in_set(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_char_in_set(s1[end - 1], set) == 1)
		end--;
	new_string = ft_substr(s1, start, (size_t)end - start);
	return (new_string);
}
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

int	ft_substr_cpy(char **subs_array, char const *s, char c, size_t substrings)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < substrings)
	{
		len = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			len++;
			i++;
		}
		if (len != 0)
		{
			if (assign_malloc(subs_array, j, len + 1))
				return (1);
		}
		ft_strlcpy(subs_array[j], &s[i - len], len + 1);
		j++;
	}
	return (0);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	source_len;
	size_t	i;

	source_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (source_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (source_len);
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

	if (!s)
		return (NULL);
	substrings = ft_count_strings(s, c);
	substrings_array = ft_calloc(substrings, sizeof(char *));
	if (!substrings_array)
		return (NULL);
	if (ft_substr_cpy(substrings_array, s, c, substrings) == 1)
		return (NULL);
	return (substrings_array);
}
int main(void)
{
	char	char1 = 'd';
	char	char2 = 'D';

	char 	*string1 = "lorem ipsum";
	char	*string2 = "The fox in the hole";
	char	*string3 = "lorem_ipsum";
	char	*string4 = "LOrem";
	char	*string5 = "             hola";
	char	*string6 = "hola                ";
	char	*string7 = "             ho la    ";
	// char	*string8 = "  hola            ";
	// char	*string9 = "             h o l a   ";

	printf("Convertir el char a mayusculas: %c\n", ft_toupper(char1));	// expect 'D'
	printf("Convertir el char a minusculas: %c\n", ft_tolower(char2));	// expect 'd'

	printf("Contar el número de caracteres de una cadena: %ld\n", ft_strlen(string1)); 	// expect 11
	printf("Contar el número de caracteres en una cadena: %ld\n", ft_strlen(string2));	// expect 19	
		printf("ft_42\n");
	printf("Busca el primer caracter dentro de una string: %s\n", ft_strchr(string1, 'm'));		// expect "m ipsum"
	printf("Busca el primer caracter dentro de una string: %s\n", ft_strchr(string1, '\0'));	// expect ""
	printf("Busca el primer caracter dentro de una string; %s\n", ft_strchr(string2, 'k'));		// expect NULL
		printf("c Lib\n");
	printf("Busca el primer caracter dentro de una string: %s\n", strchr(string1, 'm'));		// expect "m ipsum"
	printf("Busca el primer caracter dentro de una string: %s\n", strchr(string1, '\0'));		// expect ""
	printf("Busca el primer caracter dentro de una string: %s\n", strchr(string2, 'k'));		// expect NULL
		printf("ft_42\n");
	printf("Busca el último caracter dentro de una string: %s\n", ft_strrchr(string2, 'o'));	// expect "ole"
	printf("Busca el último caracter dentro de una cadena: %s\n", ft_strrchr(string2, 'a'));	// expect NULL
	printf("Busca el último caracter dentro de una cadena: %s\n", ft_strrchr(string1, '\0'));	// expect ""
		printf("c Lib\n");	
	printf("Busca el último caracter dentro de una string: %s\n", strrchr(string2, 'o'));	// expect "ole"
	printf("Busca el último caracter dentro de una cadena: %s\n", strrchr(string2, 'a'));	// expect NULL
	printf("Busca el último caracter dentro de una cadena: %s\n", strrchr(string1, '\0'));	// expect ""
		printf("ft_42\n");
	printf("Compara dos cadenas: %d\n", ft_strncmp(string1, string3, 1));	// expect 0	
	printf("Compara dos cadenas: %d\n", ft_strncmp(string1, string3, 8));	// expect -63	
	printf("Compara dos cadenas: %d\n", ft_strncmp(string1, string4, 2));	// expect 32	
	printf("Compara dos cadenas: %d\n", ft_strncmp(string1, string3, 0));	// expect 0	
	printf("Compara dos cadenas: %d\n", ft_strncmp(string1, string3, 0));	// expect 0
	printf("Compara dos cadenas: %d\n", ft_strncmp("\nabc", "\nabbc", 4));	// expect 1
		printf("c Lib\n");
	printf("Compara dos cadenas: %d\n", strncmp(string1, string3, 1));	// expect 0	
	printf("Compara dos cadenas: %d\n", strncmp(string1, string3, 8));	// expect -63
	printf("Compara dos cadenas: %d\n", strncmp(string1, string4, 2));	// expect 32
	printf("Compara dos cadenas: %d\n", strncmp(string1, string3, 0));	// expect 0	
	printf("Compara dos cadenas: %d\n", strncmp(string1, string3, 0));	// expect 0	
	printf("Compara dos cadenas: %d\n", strncmp("\nabc", "\nabbc", 4));	// expect 1
		printf("ft_42\n");
	printf("Encuentra una subcadena dentro de una cadena: %s\n", ft_strnstr(string1, "rem", 8));	// expect "rem ipsum"
	printf("Encuentra una subcadena dentro de una cadena: %s\n", ft_strnstr(string1, "", 8));	// expect "lorem ipsum"
	printf("Encuentra una subcadena dentro de una cadena: %s\n", ft_strnstr(string2, "e", 18));	// expect "e fox in the hole"
	printf("Encuentra una subcadena dentro de una cadena: %s\n", ft_strnstr(string2, "y", 10));	// expect NULL
	printf("Encuentra una subcadena dentro de una cadena: %s\n", ft_strnstr(string1, "rem", 0));	// expect NULL
	printf("Encuentra una subcadena dentro de una cadena: %s\n", ft_strnstr(string2, "fox", 1));	// expect NULL
		printf("c Lib\n"); // no funciona la funcion strnstr
	printf("Encuentra una subcadena dentro de una cadena: %s\n", strstr(string1, "rem"));	// expect rem ipsum
	printf("Encuentra una subcadena dentro de una cadena: %s\n", strstr(string1, ""));	// expect "lorem ipsum"
	printf("Encuentra una subcadena dentro de una cadena: %s\n", strstr(string2, "y"));	// expect NULL
			printf("ft_42\n");
	printf("Recorta los caracteres: %s\n", ft_strtrim(NULL, "     "));		// expect NULL
	printf("Recorta los caracteres: %s\n", ft_strtrim(string5, " ")); 		// expect "hola"
	printf("Recorta los caracteres: %s\n", ft_strtrim(string6, " "));		// expect "hola"
	printf("Recorta los caracteres: %s\n", ft_strtrim(string7, " "));		// expect "ho la"
	printf("Recorta los caracteres: %s\n", ft_strtrim(string1, "bhd"));		// expect "lorem ipsum"
	printf("Recorta los caracteres: %s\n", ft_strtrim(string1, NULL));		// expect NULL
			printf("ft_42\n");
	char **v = ft_split("hello!", 32);
	int i = 0;
	while(v[i])
		printf("%s\n", v[i++]);
	i = 0;
	while (v[i])
		free (v[i++]);
	free(v);
	
	return (0);
}