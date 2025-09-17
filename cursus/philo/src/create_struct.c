/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:49:31 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/09/17 12:14:49 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(char **argv)
{
	t_philo	*data_struct;

	data_struct = ft_calloc(1, sizeof(t_philo));
	if (!data_struct)
		return (NULL);
	if (!check_arguments(argv))
		return (NULL);
	data_struct->n_philos = ft_atoi(argv[1]);
	data_struct->tt_die = ft_atoi(argv[2]);
	data_struct->tt_eat = ft_atoi(argv[3]);
	data_struct->tt_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data_struct->eat_count = ft_atoi(argv[5]);
	return (data_struct);
}
