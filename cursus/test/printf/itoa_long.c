/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:48:33 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/13 16:14:45 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void *ft_calloc(size_t nmemb, size_t size)
{
    size_t i;                    // variable para iterar sobre los bloques de memoria
    size_t total_size;           // variable para almacenar el tamaño del numero de elementos por su tamaño
    void *memory_pointer;        // puntero para almacenar el bloque de memoria
    unsigned char *clean_memory; // puntero char para almacenar cada byte a 0

    if (nmemb == 0 || size == 0) // si algun parámetro es 0, se retorna el valor de malloc(0), el cúal siempre devuelve un puntero válido el cual se podra siempre liberar con free()
    {
        return (malloc(0));
    }
    i = 0;
    total_size = nmemb * size;           // calculamos la cantidad de memoria que necesitamos
    memory_pointer = malloc(total_size); // obtenemos el bloque de memoria con el tamaño deseado
    if (memory_pointer == NULL)          // si no podemos obtener el bloque de memoria => NULL
    {
        return NULL;
    }
    clean_memory = (unsigned char *)memory_pointer; // ese tamaño de memoria lo inicializamos a char para poder trbajar byte a byte
    while (i < total_size) // iteramos durante todos los bytes
    {
        clean_memory[i] = 0; // se inicizalizan en 0 todos los bytes no a '\0'
        i++;
    }
    return (clean_memory); // retornamos el puntero a los bloques de memoria inicializados en 0
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
static size_t	intlen(long n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
	{
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	reverse_string(char *s, size_t len)
{
	size_t	start;
	size_t	end;
	char	swap;

	start = 0;
	end = len - 1;
	{
		while (start < end)
		{
			swap = s[start];
			s[start] = s[end];
			s[end] = swap;
			start++;
			end--;
		}
	}
}

static char	*aux_itoa(char *s, long n)
{
	int 	aux;
	size_t	i;

	i = 0;
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	while (n > 0)
	{
		aux = (n % 16);
		if (aux >= 10)
		{
			s[i] = (aux - 10) + 'a';
		}
		else
		{
			s[i] = aux + '0';
		}
		n = n / 16;
		i++;
	}
	return (s);
}

char	*ft_itoa_long(long n)
{
	size_t	len;
	char	*result;
	int		position;

	len = intlen(n);
	result = ft_calloc(1, len + 1);
	if (!result)
		return (NULL);
	if (n == 2147483648)
		return (result = "-80000000");
/* 	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	} */
	if (n >= 16)
	{
	aux_itoa(result, n);
	}
	// reverse_string(result, len);
	result[len] = '\0';
	return (result);
}

int main (void)
{
	long	n = 1548512;
	char	*r;

	r = ft_itoa_long(n);
	printf("%s", r);

	return (0);
}