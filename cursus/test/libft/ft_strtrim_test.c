/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:24:51 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/20 17:53:11 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char *ft_strtrim(char const *s1, char const *set)
{
    char *new_string; // nueva string resultante despues de recortar los caracteres
    size_t i;
    size_t j;
    size_t k;

    new_string = malloc(sizeof(s1));
    i = 0;
    j = 0;
    k = 0;
    while (s1[i] != '\0' && set[j] != '\0')
    {
        while (s1[i] != '\0')
        {
            if (s1[i] != set[j])
            {
                new_string[k] = s1[i];
                k++;
            }
            i++;
        }
        j++;
        i = 0;
    }
    return (new_string);
}
int main(void)
{
    char const s1[] = "abcdeaba";
    char const set[] = "ab";
    char *result;

    result = ft_strtrim(s1, set); // expect bcdeb
    write(1, result, sizeof(result));
    free(result);
    return (0);
}