/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:09:47 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/09/17 12:29:05 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
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

// Parser

bool	check_arguments(char **arr);

// Init

t_philo	*init_philo(char **argv);

// Tests

void	print_struct(t_philo *data_struct);

#endif
