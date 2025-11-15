/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:24:04 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 13:12:09 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_tt_die(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos->meal_lock);
		if (get_time() - data->philos[i].last_meal >= (long long)data->tt_die)
		{
			print_status(&data->philos[i], DIE);
			set_death(data);
			pthread_mutex_unlock(&data->philos->meal_lock);
			return (true);
		}
		pthread_mutex_unlock(&data->philos->meal_lock);
		i++;
	}
	return (false);
}

bool	check_meals(t_data *data)
{
	size_t	i;

	if (data->eat_count == -1)
		return (false);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos->meal_lock);
		if (data->philos[i].meals < (size_t)data->eat_count)
		{
			pthread_mutex_unlock(&data->philos->meal_lock);
			return (false);
		}
		pthread_mutex_unlock(&data->philos->meal_lock);
		i++;
	}
	set_death(data);
	return (true);
}