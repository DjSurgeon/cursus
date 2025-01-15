/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:47:41 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/14 17:19:39 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int strncmp(const char *s1, const char *s2, size_t n);

int strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    i = 0;
    while (i <= n)
    {
        if (s1[i] == s2[i])
        {
            i++;
        }
        else if (s1[i] > s2[i])
        {
            return (1);
        }
        else if (s1[i] < s2[i])
        {
            return (2); // return -1
        }
    }
    return (0);
}