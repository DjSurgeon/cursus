/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:24:04 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/17 00:14:08 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file monitor_routine.c
 * @brief Functions for the simulation's monitoring thread.
 * This file contains the logic for checking philosopher starvation and
 * mandatory meal completion, which dictate when the simulation must end.
 * @note All checks must be thread-safe, utilizing mutexes to read shared
 * philosopher states.
 * @warning Failure to use mutexes during shared data access (last_meal, meals)
 * will result in race conditions and incorrect termination logic.
 */
#include "philo.h"

/**
 * @brief Checks if any philosopher has starved to death (Time To Die expired).
 * The monitor iterates through all philosophers, checking if the time elapsed
 * since their last meal is greater than or equal to `data->tt_die`.
 * @param data Pointer to the main simulation data structure.
 * @return bool **true** if a philosopher has died, **false** otherwise.
 * @note **Synchronization**: `data->philos[i].meal_lock` is acquired before
 * reading `last_meal` to ensure a consistent, non-corrupted timestamp.
 * @note If death is detected:
 * 1. The death is logged using @ref print_status.
 * 2. The global termination flag is set using @ref set_death().
 * 3. The `meal_lock` is unlocked, and the function returns `true`.
 * @see get_time()
 * @see set_death()
 * @see print_status()
 */
bool	check_tt_die(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (get_time() - data->philos[i].last_meal >= (long long)data->tt_die)
		{
			print_status(&data->philos[i], DIE);
			set_death(data);
			pthread_mutex_unlock(&data->philos[i].meal_lock);
			return (true);
		}
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		i++;
	}
	return (false);
}

/**
 * @brief Checks if all philosophers have completed the mandatory number
 * of meals.
 * This function is only executed if `data->eat_count` is not -1. It iterates
 * through all philosophers and checks if every single one has reached the
 * required meal count (`data->eat_count`).
 * @param data Pointer to the main simulation data structure.
 * @return bool **true** if all philosophers have completed their meals,
 * **false** otherwise.
 * @note If `data->eat_count == -1`, the function immediately returns `false`.
 * @note **Synchronization**: `data->philos[i].meal_lock` is acquired to safely
 * read the `data->philos[i].meals` counter.
 * @note **Early Exit**: If even one philosopher has not reached the goal, the
 * loop returns `false` immediately.
 * @note If all philosophers meet the criteria, the global termination flag is
 * set using @ref set_death() to ensure graceful termination of all active
 * threads.
 * @see set_death()
 */
bool	check_meals(t_data *data)
{
	size_t	i;

	if (data->eat_count == -1)
		return (false);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (data->philos[i].meals < (size_t)data->eat_count)
		{
			pthread_mutex_unlock(&data->philos[i].meal_lock);
			return (false);
		}
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		i++;
	}
	set_death(data);
	return (true);
}
