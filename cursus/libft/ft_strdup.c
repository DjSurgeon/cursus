/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:46:15 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/25 16:57:04 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_strdup(const char *s)
{
	char	*new_string;
	size_t	s_size;
	size_t	i;

	i = 0;
	s_size = ft_strlen(s + 1);
	new_string = malloc(s_size);
	if (new_string == NULL)
		return (NULL);
	while (i < s_size)
	{
		new_string[i] = s[i];
		i++;
	}
	return (new_string);
}
