/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:03:48 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 10:22:31 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file routines.c
 * @brief Core behavioral routines for philosophers and simulation monitoring.
 * This file contains the main execution loops for philosopher threads and
 * the monitoring thread that supervises the entire simulation.
 * @note Implements the core dining philosophers algorithm with proper
 * synchronization and deadlock prevention.
 * @warning All routines must be thread-safe and properly synchronized
 * using the provided mutexes.
 */
#include "philo.h"

/**
 * @brief Main execution routine for each philosopher thread.
 * This function represents the life cycle of a philosopher in the simulation.
 * Each philosopher continuously cycles through thinking, eating, and sleeping
 * states until the simulation ends (either by death or completion).
 * The routine implements several key strategies:
 * - Handles special case for single philosopher
 * - Implements staggered start for even-numbered philosophers to prevent
 * deadlock.
 * - Continuously checks for simulation termination via death flag
 * - Executes the full cycle: take forks → eat → drop forks → sleep → think.
 * @param arg Void pointer that will be cast to t_philo* representing
 * the individual philosopher's data.
 * @return void* Always returns NULL (required by pthreads interface).
 * @note For single philosopher case, delegates to one_philo_routine().
 * @note Even-numbered philosophers start slightly delayed to prevent
 * all philosophers grabbing left forks simultaneously (deadlock prevention).
 * @note The death check is performed at the beginning of each cycle to
 * ensure quick termination when needed.
 * @warning This function runs in a separate thread and must be thread-safe.
 * @warning All state changes must be properly synchronized with mutexes.
 * @see one_philo_routine()
 * @see check_death()
 * @see take_forks()
 * @see philo_eat()
 * @see drop_forks()
 * @see philo_sleep()
 * @see philo_think()
 */
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_philos == 1)
	{
		one_philo_routine(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!check_death(philo->data))
	{
		if (!take_forks(philo))
			return (NULL);
		philo_eat(philo);
		drop_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)arg;
	while (1)
	{
		if (check_death(data))
			return (NULL);
		i = 0;
		while (i < data->n_philos)
		{
			pthread_mutex_lock(&data->meal_lock);
			if (get_time() - data->philos[i].last_meal >= (long long)data->tt_die)
			{
				print_status(&data->philos[i], DIE);
				set_death(data);
				pthread_mutex_unlock(&data->meal_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&data->meal_lock);
			i++;
		}
	}
	return (NULL);
}
