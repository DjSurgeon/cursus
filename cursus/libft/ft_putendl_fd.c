/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:16 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 12:26:21 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: print a string and new line in file descriptor number
**	parameters: string and file descriptor
**	return:  none
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	*new_line;

	new_line = (char *) '\n';
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write (fd, &new_line, 1);
}
