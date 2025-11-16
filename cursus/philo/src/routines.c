/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:03:48 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 23:29:36 by sergio-jime      ###   ########.fr       */
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
 * This function represents the life cycle of a philosopher: continuously
 * cycling through thinking, eating, and sleeping states until the
 * simulation ends.
 * @param arg Void pointer that will be cast to @ref t_philo* representing
 * the individual philosopher's data.
 * @return void* Always returns NULL (required by pthreads interface).
 * @note **Single Philosopher Case**: Delegates to @ref one_philo_routine()
 * to handle the unique case where a single philosopher cannot eat.
 * @note **Deadlock Prevention (Staggered Start)**: Even-numbered philosophers
 * introduce a small delay (`ft_usleep(100)`) at the start to stagger fork
 * acquisition and avoid simultaneous attempts to grab the left fork, which
 * would lead to a circular wait deadlock.
 * @note **Termination**: The loop condition `!check_death(philo->data)` and
 * the intermediate check `philos_stop(philo)` ensure the philosopher stops
 * immediately if another dies or if the required meal count is reached.
 * @see one_philo_routine()
 * @see take_forks()
 * @see philo_eat()
 * @see philo_sleep()
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
		ft_usleep(100);
	while (!check_death(philo->data))
	{
		if (!take_forks(philo))
			return (NULL);
		philo_eat(philo);
		drop_forks(philo);
		if (philos_stop(philo))
			return (NULL);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

/**
 * @brief Main execution routine for the simulation monitor thread.
 * This function runs continuously in a separate thread, checking
 * the state of all philosophers to determine if the simulation
 * should terminate.
 * @param arg Void pointer that will be cast to @ref t_data*.
 * @return void* Always returns NULL (required by pthreads interface).
 * @note **Termination Checks Order**: The monitor performs three sequential
 * checks in a continuous loop, ensuring termination is handled correctly:
 * 1. @ref check_meals: Checks if all philosophers have reached the mandatory
 * meal count (`data->eat_count`). If true, the simulation ends gracefully.
 * 2. @ref check_tt_die: Checks if any philosopher has starved
 * (`time_to_die` expired).
 * If a death is detected, it triggers the global death flag.
 * 3. @ref check_death: Performs a final check on the global death flag, which
 * will be set by `check_tt_die` or an external error, ensuring the monitor
 * loop breaks.
 * @warning The monitor must access shared data (last meal time, meal count)
 * using the correct synchronization primitives (`meal_lock`) to avoid
 * race conditions.
 * The loop terminates and returns NULL as soon as any check returns true,
 * signaling the end of the simulation.
 * @see check_meals()
 * @see check_tt_die()
 */
void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_meals(data))
			return (NULL);
		if (check_tt_die(data))
			return (NULL);
		if (check_death(data))
			return (NULL);
	}
	return (NULL);
}
