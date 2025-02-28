/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:04:09 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/18 11:50:38 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(char const *str, ...);
int		ft_countchar(char c);
int		ft_countstr(char *s);
int		ft_countint(int n);
int		ft_countunsig(unsigned int n);
int		ft_counthexalo(unsigned long long n);
int		ft_counthexaup(unsigned long long n);
int		ft_countpointer(uintptr_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strchr(const char *s, int c);

#endif