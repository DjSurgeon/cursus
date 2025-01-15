/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:56:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 13:00:08 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int main (void)
{
    char big[] = "Hola mundo";
    char little[] = "la";
    size_t len = 5;
    
    strnstr(big, little, len);

    return (0);
}