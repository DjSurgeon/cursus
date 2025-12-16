/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:48:01 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/22 13:48:04 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

int		ft_printf(char const *fix_arg, ...);
int		len_int_nbr(int n);
int		write_char(int c);
int		write_hex(unsigned long hex, int flag);
int		write_int_nbr(int n);
int		write_ptr(void *ptr);
int		write_str(char *str);
int		write_uns_int_nbr(unsigned int uns_nbr);

#endif
