/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:47:38 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/28 12:38:56 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
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
	if (memory_pointer == NULL)
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
size_t ft_strlen(const char *s)
{
    size_t i;
    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *new_substring; // puntero a la substring de s
    size_t i;            // variable para iterar

    i = 0;
    if (s == NULL)
        return (NULL);
    // new_substring = malloc(len + 1); // guardamos la memoria de la substring mas el caracter nulo
    new_substring = ft_calloc(1, len + 1);
    if (new_substring == NULL)
        return (NULL); // Si tenemos algun error al reservar la memoria devolvemos NULL, o si la entrada de la string a copiar es NULL tambien tendremos la misma respuesta
    while (i < len)
    {
        new_substring[i] = s[start]; // copiamos desde el indice start durante len y dejamos el ultimo para el caracter '\0'
        i++;
        start++;
    }
    new_substring[i] = '\0';
    return (new_substring);
}

int main(void)
{
    char s[] = "Hello World!";
    unsigned int start = 7;
    size_t len = 3;

    char *result;

    result = ft_substr(s, start, len);
    write(1, result, ft_strlen(result));

    free(result);

    return (0);
}