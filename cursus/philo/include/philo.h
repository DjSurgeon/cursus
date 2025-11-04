/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:09:47 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/04 14:13:53 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

// Structs

typedef struct s_philo
{
	size_t	n_philos;
	size_t	tt_die;
	size_t	tt_eat;
	size_t	tt_sleep;
	size_t	eat_count;
}				t_philo;

// Utils

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);

// Parser

bool	check_arguments(char **arr);

// Init

t_philo	*init_philo(char **argv);

// Tests

void	print_struct(t_philo *data_struct);

#endif
