/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_exam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:45:38 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/13 16:45:41 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Cuenta cuántas palabras hay en 's' separadas por 'c'
static size_t  count_words(char const *s, char c)
{
    size_t  i = 0;
    size_t  count = 0;

    while (s[i])
    {
        // Saltar delimitadores
        while (s[i] && s[i] == c)
            i++;
        if (s[i] && s[i] != c)
        {
            count++;
            // Avanzar hasta el final de la palabra
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (count);
}

// Copia desde s[pos] hasta encontrar 'c' o '\0', reservando y devolviendo el puntero
static char     *extract_word(char const *s, char c, size_t *pos)
{
    size_t  start = *pos;
    size_t  len = 0;
    char    *word;
    size_t  i;

    // Medir longitud
    while (s[*pos] && s[*pos] != c)
    {
        len++;
        (*pos)++;
    }
    // Reservar espacio (+1 para '\0')
    word = malloc(len + 1);
    if (!word)
        return (NULL);
    // Copiar manualmente
    i = 0;
    while (i < len)
    {
        word[i] = s[start + i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

// Libera el array de palabras en caso de error
static void     free_split(char **arr, size_t filled)
{
    size_t  i;

    for (i = 0; i < filled; i++)
        free(arr[i]);
    free(arr);
}

// Función principal
char    **ft_split(char const *s, char c)
{
    size_t  words;
    char    **res;
    size_t  i = 0;
    size_t  pos = 0;

    if (!s)
        return (NULL);
    words = count_words(s, c);
    res = malloc((words + 1) * sizeof(char *));
    if (!res)
        return (NULL);
    res[words] = NULL;

    while (i < words)
    {
        // Saltar delimitadores antes de cada palabra
        while (s[pos] && s[pos] == c)
            pos++;
        // Extraer y asignar palabra
        res[i] = extract_word(s, c, &pos);
        if (!res[i])
        {
            free_split(res, i);
            return (NULL);
        }
        i++;
    }
    return (res);
}
