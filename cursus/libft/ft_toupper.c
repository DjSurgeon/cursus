/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:40:58 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/13 23:30:59 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_toupper (int c);

int ft_toupper (int c)
{
    if (c >= 97 && c <= 122)
    {
        c-= 32;
        return (c);
    }
    else
    {
        return (c);
    }
}