/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:36:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/17 00:09:27 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file routine_utils.c
 * @brief Utility functions supporting philosopher routines and simulation
 * management.
 * This file contains helper functions for special cases, status reporting,
 * and death checking that are used throughout the philosopher routines.
 * @note Implements thread-safe operations with proper synchronization.
 */
#include "philo.h"

/**
 * @brief Special routine for simulations with only one philosopher.
 * This function handles the edge case where N=1. The philosopher takes the
 * single available fork, logs the action, and then waits for the entire
 * `time_to_die` duration before the monitor thread detects the inevitable
 * starvation and death.
 * @param philo Pointer to the philosopher's individual data structure.
 * @see print_status()
 * @see ft_usleep()
 */
void	one_philo_routine(t_philo *philo)
{
	print_status(philo, FORK);
	ft_usleep(philo->data->tt_die);
}

/**
 * @brief Thread-safe function for printing philosopher status messages.
 * This function safely logs philosopher state changes to stdout while
 * preventing interleaved output from multiple threads. It ensures atomicity
 * and prevents messages from being printed after the simulation has terminated
 * by death.
 * @param philo Pointer to the philosopher's individual data structure.
 * @param str String describing the philosopher's current state/action
 * (e.g., "is thinking", "died").
 * @note Uses `data->write_lock` mutex to guarantee that only one thread can
 * write to stdout at a time.
 * @note Calculates the relative timestamp (`get_time() - data->start_t`) for
 * accurate logging.
 * @warning The death check before and inside the lock ensures that the output
 * stops immediately when the global death flag is set.
 * @see check_death()
 * @see get_time()
 */
void	print_status(t_philo *philo, char *str)
{
	long long	timestamp;

	if (check_death(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->write_lock);
	if (!check_death(philo->data))
	{
		timestamp = get_time() - philo->data->start_t;
		printf("%lld %zu %s\n", timestamp, philo->id, str);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

/**
 * @brief Safely checks if the simulation should terminate due to a
 * philosopher's death.
 * Provides thread-safe access to the global `data->philo_died` flag.
 * @param data Pointer to the main simulation data structure.
 * @return bool **true** if a philosopher has died and simulation
 * should terminate, **false** otherwise.
 * @note The `death_lock` mutex protects the `philo_died` flag against race
 * conditions during simultaneous read/write access from the monitor and
 * philosopher threads.
 */
bool	check_death(t_data *data)
{
	bool	dead;

	dead = false;
	pthread_mutex_lock(&data->death_lock);
	if (data->philo_died == 1)
		dead = true;
	pthread_mutex_unlock(&data->death_lock);
	return (dead);
}

/**
 * @brief Safely sets the global simulation termination flag.
 * This function is used by the monitor thread when a philosopher's death
 * is detected, signaling all other threads to terminate.
 * @param data Pointer to the main simulation data structure.
 * @note Uses the `death_lock` mutex to ensure the update to `philo_died`
 * is atomic and immediately visible to all other threads.
 * @warning Should only be called by the monitor thread (or during thread
 * creation error handling) to manage simulation termination.
 * @see check_death()
 */
void	set_death(t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	data->philo_died = 1;
	pthread_mutex_unlock(&data->death_lock);
}

/**
 * @brief Checks if a philosopher has completed their mandatory number of meals.
 * This function determines if the optional `eat_count` argument has been
 * satisfied for the current philosopher. If satisfied, the philosopher
 * thread should terminate gracefully.
 * @param philo Pointer to the philosopher's individual data structure.
 * @return bool **true** if `eat_count` is defined and `philo->meals` has
 * reached the limit, **false** otherwise.
 * @note If `data->eat_count` is -1, the check is skipped, and the
 * philosopher runs indefinitely (until death).
 * @note Uses `philo->meal_lock` to safely read the `philo->meals` counter.
 */
bool	philos_stop(t_philo *philo)
{
	if (philo->data->eat_count == -1)
		return (false);
	pthread_mutex_lock(&philo->meal_lock);
	if (philo->meals == (size_t)philo->data->eat_count)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->meal_lock);
	return (false);
}
