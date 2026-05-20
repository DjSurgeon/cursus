/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:46:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/21 17:23:57 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file check_errors.c
 * @brief Outputs error messages to standard error (stderr).
 * Provides a centralized error reporting mechanism for the FDF program.
 * Writes the specified error message to the standard error stream (fd 2)
 * using the ft_putstr_fd function from libft.
 * @param str Error message string to display. The string should be
 * null-terminated.
 * @return void
 */
void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
}
