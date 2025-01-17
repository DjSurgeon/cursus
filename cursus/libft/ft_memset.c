/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:56:12 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 12:04:53 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_memset (void *s, int c, size_t n)
{
    char *a;
    unsigned char d;
    size_t i;
    
    d = (unsigned char) c;
    a = (char *)s;       
    i = 0;
    
    while (i < n)
    {
        a[i] = d;
        i++;
    }
    return (s);
}