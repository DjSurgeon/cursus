/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:47:58 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/25 16:57:44 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	new_string_len;
	size_t	i;
	char	*new_string;

	if(s == NULL)
		return (NULL);
	new_string_len = ft_strlen(s);
	i = 0;
	new_string = (char *)malloc(new_string_len + 1);
	if (!new_string)
		return (NULL);
	while (s[i] != '\0')
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return ( new_string);
}