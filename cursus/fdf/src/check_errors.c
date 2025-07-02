/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:46:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 22:27:34 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Outputs error messages to standard error (stderr).
 * Provides a centralized error reporting mechanism for the FDF program.
 * Writes the specified error message to the standard error stream (fd 2).
 * @param str Error message string to display.
 * @return void.
 */
void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
}
