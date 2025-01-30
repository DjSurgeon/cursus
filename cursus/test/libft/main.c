/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:59:49 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/29 13:24:08 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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
int main(void)
{
	char	char1 = 'd';
	char	char2 = 'D';

	char 	*string1 = "lorem ipsum";
	char	*string2 = "The fox in the hole";
	char	*string3 = "lorem_ipsum";
	char	*string4 = "LOrem";

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
		printf("c Lib\n"); // no funcionala funcion strnstr
	printf("Encuentra una subcadena dentro de una cadena: %s\n", strstr(string1, "rem"));	// expect rem ipsum
	printf("Encuentra una subcadena dentro de una cadena: %s\n", strstr(string1, ""));	// expect "lorem ipsum"
	printf("Encuentra una subcadena dentro de una cadena: %s\n", strstr(string2, "y"));	// expect NULL
	return (0);
}