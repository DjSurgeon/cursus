/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:39:53 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/17 02:21:34 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{	
/*
**	%c imprimir un solo caracter
*/

char	char1 = 'a';
char	char2 = 'Z';

printf("El conversor %%c imprime un solo carácter\n");
printf("%c char a\n", char1);
printf("%c char Z\n", char2);
printf("%c char 4\n", '4');

/*
**	%s imprimir una string
*/

char	*string1 = "Hola 42!";
char	*string2 = "Hi baby ;)";

printf("El conversor %%s imprime una string\n");
printf("%s\n", string1);
printf("%s\n", string2);
printf("%s\n", "Hola desde una string");

/*
**	%p un puntero void, en formato hexadecimal
*/
int		num1 = 5;
void	*pointer1 = &num1;
void	*pointer2 = string1; // string1 es un puntero a char *, apunta a la primera posición de la cadena
void	*pointer3 = &string1;

printf("El conversor %%p imprime un puntero en forma hexadecimal\n");
printf("Puntero a un int: %p\n", pointer1); 		//dirección de memoria en la pila (stack)
printf("Puntero a una string: %p\n", pointer2);		//dirección de memoria de segmento de texto
printf("Puntero a un string: %p\n", pointer3);		//dirección de memoria en la pila (stack)
printf("Puntero a un string: %p\n", pointer3);		//dirección de memoria en la pila (stack)


/*
**	%d un número decimal en base 10 %i un entero en base 10
**	%u un número decimal sin signo
**	en printf %d y %i tienen el mismo uso
** en scanf %i si es capaz de reconocer distintas bases
*/

int		num2 = 5462;
int		num3 = -451233;
unsigned int	num5 = 4294964295;
unsigned int	num6 = 1515161;

printf("El conversor %%d imprime un numero en base 10\n");
printf("Número 5462: %d\n", num2);
printf("Número -451233: %d\n", num3);
printf("El conversor %%i imprime un entero en base 10\n");
printf("Número 5462: %i\n", num2);
printf("Número -451233: %i\n", num3);
printf("El conversor %%u imprime un entero sin signo\n");
printf("Número 4294964295: %u\n", num5);
printf("Número 1515161: %u\n", num6);

/*
**	%x imprime un número hexadecimal en minusculas
**	%X imprime un número hezadecimal en mayusculas
*/

int	num7 = 10;
int	num8 = 25;
int	num9 = 465821;

printf("El conversor %%x y %%X imprimen numeros hexadecimales en minusculas y mayusculas respectivamente\n");
printf("Número 10 -> %x\n", num7);
printf("Número 25 -> %x\n", num8);
printf("Número 465821 -> %x\n", num9);
printf("Número 10 -> %X\n", num7);
printf("Número 25 -> %X\n", num8);
printf("Número 465821 -> %X\n", num9);

/*
**	el valor de retorno de la función printf es un int que indica el número de carácteres impresos
*/

int	chars;
			//	12345678
chars = printf("hola 42\n");	// return 8
printf("%i\n", chars);
			//		 1  2 1
chars = printf("hola %% %i\n", 42);	// return 10
printf("%i\n", chars);

char	char10 = 'a';
char	char20 = 'Z';

ft_printf("El conversor %%c imprime un solo carácter\n");
ft_printf("%c char a\n", char10);
ft_printf("%c char Z\n", char20);
ft_printf("%c char 4\n", '4');

/*
**	%s imprimir una string
*/

char	*string10 = "Hola 42!";
char	*string20 = "Hi baby ;)";

ft_printf("El conversor %%s imprime una string\n");
ft_printf("%s\n", string10);
ft_printf("%s\n", string20);
ft_printf("%s\n", "Hola desde una string");

/*
**	%p un puntero void, en formato hexadecimal
*/
int		num10 = 5;
void	*pointer10 = &num10;
void	*pointer20 = string10; // string1 es un puntero a char *, apunta a la primera posición de la cadena
void	*pointer30 = &string10;

ft_printf("El conversor %%p imprime un puntero en forma hexadecimal\n");
ft_printf("Puntero a un int: %p\n", pointer10); 		//dirección de memoria en la pila (stack)
ft_printf("Puntero a una string: %p\n", pointer20);		//dirección de memoria de segmento de texto
ft_printf("Puntero a un string: %p\n", pointer30);		//dirección de memoria en la pila (stack)
ft_printf("Puntero a un string: %p\n", pointer30);		//dirección de memoria en la pila (stack)


/*
**	%d un número decimal en base 10 %i un entero en base 10
**	%u un número decimal sin signo
**	en printf %d y %i tienen el mismo uso
** en scanf %i si es capaz de reconocer distintas bases
*/

int		num20 = 5462;
int		num30 = -451233;
unsigned int	num50 = 4294964295;
unsigned int	num60 = 1515161;

ft_printf("El conversor %%d imprime un numero en base 10\n");
ft_printf("Número 5462: %d\n", num20);
ft_printf("Número -451233: %d\n", num30);
ft_printf("El conversor %%i imprime un entero en base 10\n");
ft_printf("Número 5462: %i\n", num20);
ft_printf("Número -451233: %i\n", num30);
ft_printf("El conversor %%u imprime un entero sin signo\n");
ft_printf("Número 4294964295: %u\n", num50);
ft_printf("Número 1515161: %u\n", num60);

/*
**	%x imprime un número hexadecimal en minusculas
**	%X imprime un número hezadecimal en mayusculas
*/

int	num70 = 10;
int	num80 = 25;
int	num90 = 465821;

ft_printf("El conversor %%x y %%X imprimen numeros hexadecimales en minusculas y mayusculas respectivamente\n");
ft_printf("Número 10 -> %x\n", num70);
ft_printf("Número 25 -> %x\n", num80);
ft_printf("Número 465821 -> %x\n", num90);
ft_printf("Número 10 -> %X\n", num70);
ft_printf("Número 25 -> %X\n", num80);
ft_printf("Número 465821 -> %X\n", num90);

/*
**	el valor de retorno de la función printf es un int que indica el número de carácteres impresos
*/

int	chars0;
			//	12345678
chars0 = ft_printf("hola 42\n");	// return 8
ft_printf("%i\n", chars0);
			//		 1  2 1
chars0 = ft_printf("hola %% %i\n", 42);	// return 10
ft_printf("%i\n", chars0);

ft_printf("\n\n\n\n#### TEST ####\n");

// ft_printf("ft %p \n", 1);
// printf("cc %d \n", 1);
// ft_printf("ft %x \n", ULONG_MAX);
// printf("cc %lx \n", ULONG_MAX);
// ft_printf("ft %x \n", LONG_MIN);
// printf("cc %lx \n", LONG_MIN);
// ft_printf("ft %p \n", 15);
// printf("cc %d \n", 15);
// ft_printf("ft - This is a %c %s %d %x %X %p %%\n", 'c', "string", INT_MIN, ULLONG_MAX, ULONG_MAX, "pointer");
// printf("cc - This is a %c %s %d %llx %lX %p %%\n", 'c', "string", INT_MIN, ULLONG_MAX, ULONG_MAX, "pointer");


int d = ft_printf("%x %% %c %% %s, %p, %i %d, %%%%%% %% %u %x %X %% %s %c\n", 402, 'b', "hi ;=()", "char *", 4567, -1234, 9876, 9876, 9875, "lol", '\t');
int f =    printf("%x %% %c %% %s, %p, %i %d, %%%%%% %% %u %x %X %% %s %c\n", 402, 'b', "hi ;=()", "char *", 4567, -1234, 9876, 9876, 9875, "lol", '\t');

ft_printf("%d", d);
printf("%d", f);

	return (0);
}