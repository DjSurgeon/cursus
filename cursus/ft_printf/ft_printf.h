/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:04:09 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/16 23:58:57 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_countchar(char c);
int	ft_countstr(char *s);
int	ft_countint(int n);
int	ft_countunsig(unsigned int n);
int	ft_counthexalo(long n);
int	ft_counthexaup(long n);
int	ft_countpointer(long n);

#endif