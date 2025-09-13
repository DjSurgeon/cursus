/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:05:19 by serjimen          #+#    #+#             */
/*   Updated: 2025/07/21 17:39:07 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putstr_fd.c
 * @brief Writes a string to the specified file descriptor.
 * This function writes a null-terminated string to the given
 * file descriptor.
 * It handles the output character by character using the write system call.
 * @note This function does not append a newline character automatically.
 * The function will continue writing writing until it encounters the null
 * terminator.
 * No bounds checking is performed on the file descriptor.
 * @param s The null-terminated string to be written. If NULL, the behavior
 * is undefined.
 * @param fd The file descriptor where the string will be written. For example
 * 1 (stdout) or 2 (stderr).
 * @return void
 */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}
