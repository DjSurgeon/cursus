/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:05:13 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/20 16:53:43 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITAL_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
int		ft_isspace(int c);
int		ft_atoi(const char *str);
void	ft_putchar_fd(unsigned char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *s, int fd);

typedef struct s_buffer
{
	char			*str;
	int				bit_count;
	char			current_char;
	pid_t			client_pid;
}					t_buffer;

#endif
