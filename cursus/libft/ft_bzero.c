/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:57:07 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/17 14:50:21 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_bzero (void *s , size_t n)
{
    unsigned char *string;
    size_t i;
    string = (unsigned char *)s;
    i = 0;
    
    while (i < n)
    {
        string[i] = '\0';
        i++;
    }
}