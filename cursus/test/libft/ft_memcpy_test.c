/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:29:24 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/20 11:49:58 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *destination;
    unsigned char *source;
    size_t i;

    destination = (unsigned char *)dest;
    source = (unsigned char *)src;
    i = 0;

    while (i < n)
    {
        destination[i] = source[i];
        i++;
    }
    return ((void *)destination);
}

int main(void)
{
    char string1[] = "Hello 42!";
    char string2[] = "Hola!";
    size_t size1 = 5;

    int num1 = 2;
    int num2 = 8;
    int *number1 = &num1;
    int *number2 = &num2;
    size_t size2 = 4;

    char string3[] = "0123456789";
    size_t size3 = 3;

    ft_memcpy(string1, string2, size1);
    ft_memcpy(number1, number2, size2);
    ft_memcpy(string3 + 1, string3, size3);

    return (0);
}