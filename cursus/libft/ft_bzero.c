/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:57:07 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 11:44:03 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_bzero (void *s , size_t n)
{
    char *c;
    size_t i;
    c = (char *)s;
    i = 0;
    
    while (i < n)
    {
        c[i] = '\0';
        i++;
    }
}