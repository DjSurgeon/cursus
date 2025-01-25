/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:58:47 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/25 10:19:09 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t  i;

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