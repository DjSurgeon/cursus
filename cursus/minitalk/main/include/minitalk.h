/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:05:13 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/22 13:07:39 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
** @file minitalk.h
** @brief Main header file for the Minitalk project.
**
** Contains libraries, macros, and function prototypes used by both
** the client and the server.
*/

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_isspace(int c);
int		ft_atoi(const char *str);
void	ft_putchar_fd(unsigned char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *s, int fd);

#endif
