/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:13:32 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/11 12:40:59 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
**	el prototipo de la función printf es	int 	ft_printf(char cont *, ...);
**	printf es epecial por que recibe un numero variable de parametros
**	el primer parametro es fijo y es la cadena de formato
**	en ella se incluye el texto a imprimir y las marcas a reemplazar por texto
**	que se obtiene de los parametros adicionales
**	por lo tanto printf se llama con tantos parametros como marcas haya en la 
** cadena de formato.
*/

int main (void)
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

	return (0);
}