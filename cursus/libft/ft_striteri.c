/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:58:47 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 16:31:52 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: apply a function at every character of the string
**	parameters:	the string and the function
**	return: none
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
	{
		return;
	}
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
