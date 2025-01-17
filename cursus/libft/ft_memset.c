/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:56:12 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 15:14:30 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_memset (void *s, int c, size_t n)
{
    unsigned char *string;
    unsigned char character;
    size_t i;
    
    character = (unsigned char) c;
    string = (unsigned char *)s;       
    i = 0;
    
    while (i < n)
    {
        string[i] = character;
        i++;
    }
    return ((void *)s);
}