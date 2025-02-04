/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:59:49 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/04 01:11:08 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <stdlib.h>

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

	char	*stringnum1 = "0";
	char	*stringnum2 = "    42";
	char	*stringnum3 = " \f\v\n-42";
	char	*stringnum4 = "2147483647";
	char	*stringnum5 = "-2147483648";
	char	*stringnum6 = "1234a42";

	int		number1 = 0;
	int		number2 = 2147483647;
	int		number3 = -2147483648;
	int		number4 = -42;

	char	*stringcmp1 = "abcdefghij";
	char	*stringcmp2 = "abcdEfghij";
	char	*stringcmp3 = "Abcdefghij";
//	char	*stringcmp4 = "abcdefghiJ";
	char	*stringcmp5 = "";
	char	*stringcmp6 = "ZSD";
	
	printf("== Atoi function\n");
		printf("ft_42\n");
	printf("string = 0 -> int = %i\n", ft_atoi(stringnum1));
	printf("string =     42 -> int = %i\n", ft_atoi(stringnum2));
	printf("string = \\f\\v\\n-42 -> int = %i\n", ft_atoi(stringnum3));
	printf("string = 2147483647 -> int = %i\n", ft_atoi(stringnum4));
	printf("string = -2147483648 -> int = %i\n", ft_atoi(stringnum5));
	printf("string = 1234a42 -> int = %i\n", ft_atoi(stringnum6));
		printf("c Lib\n");
	printf("string = 0 -> int = %i\n", atoi(stringnum1));
	printf("string =     42 -> int = %i\n", atoi(stringnum2));
	printf("string = \\f\\v\\n-42 -> int = %i\n", atoi(stringnum3));
	printf("string = 2147483647 -> int = %i\n", atoi(stringnum4));
	printf("string = -2147483648 -> int = %i\n", atoi(stringnum5));
	printf("string = 1234a42 -> int = %i\n", atoi(stringnum6));
		printf("==============================\n");
	printf("== Itoa function\n");
			printf("ft_42\n");
	printf("int = 0 -> string = %s\n", ft_itoa(number1));
	printf("int = 2147483647 -> string = %s\n", ft_itoa(number2));
	printf("int = -2147483648 -> string = %s\n", ft_itoa(number3));
	printf("int = -42 -> string = %s\n", ft_itoa(number4));
		printf("==============================\n");
	printf("== memcmp function\n");
		printf("ft_42\n");
	printf("string1 = abcdefghij -> string2 = abcdefghij = result = %i\n", ft_memcmp(stringcmp1, stringcmp1, 10));
	printf("string1 = abcdefghij -> string2 = abcdEfghij = result = %i\n", ft_memcmp(stringcmp1, stringcmp2, 10));
	printf("string1 = abcdefghij -> string2 = Abcdefghij = result = %i\n", ft_memcmp(stringcmp1, stringcmp3, 10));
	printf("string1 = abcdefghij -> string2 = '' = result = %i\n", ft_memcmp(stringcmp1, stringcmp5, 10));
	printf("string1 = abcdefghij -> string2 = ZSD = result = %i\n", ft_memcmp(stringcmp1, stringcmp6, 10));
		printf("c Lib");
	printf("string1 = abcdefghij -> string2 = abcdefghij = result = %i\n", memcmp(stringcmp1, stringcmp1, 10));
	printf("string1 = abcdefghij -> string2 = abcdEfghij = result = %i\n", memcmp(stringcmp1, stringcmp2, 10));
	printf("string1 = abcdefghij -> string2 = Abcdefghij = result = %i\n", memcmp(stringcmp1, stringcmp3, 10));
	printf("string1 = abcdefghij -> string2 = '' = result = %i\n", memcmp(stringcmp1, stringcmp5, 1));
	printf("string1 = abcdefghij -> string2 = ZSD = result = %i\n", memcmp(stringcmp1, stringcmp6, 4));



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