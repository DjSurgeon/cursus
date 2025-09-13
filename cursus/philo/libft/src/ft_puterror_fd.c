/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:39:02 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/21 17:28:56 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_puterror_fd.c
 * @brief Writes a string to the standard error output (file descriptor 2).
 * This function provides a convenient way to output error messages to stderr.
 * It serves as a wrapper around ft_putstr_fd, specifically targeting the
 * standard error stream (fd 2) which is the conventional output for error
 * messages in Unix-like systems.
 * @note This function does not append a newline character autopmatically.
 * @param str Null-terminated string to be written to stderr. If NULL,
 * the behavior is undefined.
 * @return void
 */
void	ft_puterror_fd(char *str)
{
	ft_putstr_fd(str, 2);
}
