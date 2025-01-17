/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:43:30 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 13:05:48 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_memchr (const void *s, int c, size_t n)
{
    unsigned char *d;
    unsigned char a;
    size_t i;

    d = (unsigned char *) s;
    a = (unsigned char) c;   
    i = 0;

    while (i < n)
    {
        if (d[i] == a)
        {
            return ((void *)s + i); // TODO esta linea
        }
        i++;
    }
    return (NULL);
}
int main(void)
{
    char s[] = "Hello 42!";
    int c = 32;
    size_t size = 7;
    
    ft_memchr(s, c, size);

    return (0);
}