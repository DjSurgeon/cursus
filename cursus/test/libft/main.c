/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:59:49 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/29 01:49:40 by serjimen         ###   ########.fr       */
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
int main(void)
{
	char	char1 = 'd';
	char	char2 = 'D';

	char 	*string1 = "lorem ipsum";
	char	*string2 = "The fox in the hole";

	printf("Convertir el char a mayusculas: %c\n", ft_toupper(char1));	// expect 'D'
	printf("Convertir el char a minusculas: %c\n", ft_tolower(char2));	// expect 'd'

	printf("Contar el número de caracteres de una cadena: %ld\n", ft_strlen(string1)); 	// expect 11
	printf("Contar el número de caracteres en una cadena: %ld\n", ft_strlen(string2));	// expect 19	

	printf("Busca el primer caracter dentro de una string: %s\n", ft_strchr(string1, 'm'));		// expect "m ipsum"
	printf("Busca el primer caracter dentro de una string: %s\n", ft_strchr(string1, '\0'));	// expect ""
	printf("Busca el primer caracter dentro de una string; %s\n", ft_strchr(string2, 'k'));		// expect NULL
	
	printf("Busca el primer caracter dentro de una string: %s\n", strchr(string1, 'm'));		// expect "m ipsum"
	printf("Busca el primer caracter dentro de una string: %s\n", strchr(string1, '\0'));		// expect ""
	printf("Busca el primer caracter dentro de una string: %s\n", strchr(string2, 'k'));		// expect NULL
		
	printf("Busca el último caracter dentro de una string: %s\n", ft_strrchr(string2, 'o'));	// expect "ole"
	printf("Busca el último caracter dentro de una cadena: %s\n", ft_strrchr(string2, 'a'));	// expect NULL
	printf("Busca el último caracter dentro de una cadena: %s\n", ft_strrchr(string1, '\0'));	// expect ""
	
	printf("Busca el último caracter dentro de una string: %s\n", strrchr(string2, 'o'));	// expect "ole"
	printf("Busca el último caracter dentro de una cadena: %s\n", strrchr(string2, 'a'));	// expect NULL
	printf("Busca el último caracter dentro de una cadena: %s\n", strrchr(string1, '\0'));	// expect ""

	
	return (0);
}