/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:54:26 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/18 17:42:03 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_memcmp (const void *s1, const void *s2, size_t n)
{
        unsigned char *memory1; // Area de memoria 1 a comparar
        unsigned char *memory2; // Area de memoria 2 a comparar
        size_t i;   // Contador para iterar sobre la memoria

        memory1 = (unsigned char *) s1; // Casteamos a unsigned char el primer parámetro
        memory2 = (unsigned char *) s2; // Casteamos a unsigned char el segundo parámetro
        i = 0;  // i comienza en 0

        while (i < n)   // Iteramos durante n bytes
        {
            if (memory1[i] < memory2[i])
            {
                return (-1);    // Si el area de memoria 1 es menor devuelve un número negativo
            }   
            else if (memory1[i] > memory2[i])
            {
                return (1);     // Si el area de memoria 1 es mayor devuelve un número positivo
            }
            i++;
        }
        return (0);     // Si las areas de memoria son iguales o si el parámetro n es 0, retornamos 0 
}
int main (void)
{
    char s1[] = "hello";
    char s2[] = "hello";
    size_t size0 = 0;
    size_t size1 = 3;
    size_t size2 = 7; // comportamiento indefinido ya que superamos el tamaño de las cadenas originales
    char s3[] = "HELLO";
    
    int num1 = 9; 
    int num2 = 8;
    int *number1 = &num1;
    int *number2 = &num2;
    size_t size3 = 4;

    char result = ft_memcmp(s1, s2, size0) + '0';
    char result1 = ft_memcmp(s1, s2, size1) + '0';
    char result2 = ft_memcmp(s1, s2, size2) + '0';
    char result3 = ft_memcmp(s1, s3, size2) + '0';
    char result4 = ft_memcmp(number1, number2, size3) + '0';    // size tiene que ser 4, ya que es el tamaño de un int, sino puede haber comportamientos indefinidos
 
    write (1, &result, 1); // expect 0
    write (1, &result1, 1); // expect 0
    write (1, &result2, 1); // undefined
    write (1, &result3, 1); // expect 1   
    write (1, &result4, 1); //expect 1
    return (0);
}