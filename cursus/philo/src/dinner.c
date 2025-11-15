/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:46:43 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 23:32:49 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dinner.c
 * @brief Core simulation management functions for the Philosophers dinner.
 * This file contains the main orchestration functions that start, manage,
 * and coordinate the philosopher threads and monitor thread during the
 * dining philosophers simulation.
 * @note Implements robust thread creation with proper error handling
 * and cleanup.
 * @warning All thread operations must be properly synchronized to prevent
 * race conditions and ensure clean termination.
 */
#include "philo.h"

/**
 * @brief Initializes the timing for all philosophers at the start of dinner.
 * This function sets the simulation start time and initializes the last meal
 * time for all philosophers to ensure consistent timing from the beginning
 * of the simulation.
 * @param data Pointer to the main simulation data structure.
 * @note Uses get_time() to get the current timestamp for simulation start.
 * @note All philosophers start with their last_meal set to the same start time.
 * @warning Must be called immediately before thread creation to ensure
 * accurate timing measurements.
 * @see get_time()
 */
static void	set_time_dinner(t_data *data)
{
	size_t	i;

	i = 0;
	data->start_t = get_time();
	while (i < data->n_philos)
	{
		data->philos[i].last_meal = data->start_t;
		i++;
	}
}

/**
 * @brief Creates all philosopher threads for the simulation.
 * This function creates one thread for each philosopher using the
 * philo_routine function. If any thread creation fails, it immediately
 * stops creation and joins all previously created threads to ensure
 * clean termination.
 * @param data Pointer to the main simulation data structure.
 * @return bool true if all threads are successfully created, false if any
 * thread creation fails.
 * @note Uses pthread_create to launch each philosopher's execution thread.
 * @note Implements rollback cleanup: if thread N fails to create,
 * threads 0 to N-1 are properly joined before returning.
 * @note Each thread receives a pointer to its individual philosopher structure.
 * @warning Thread creation failures trigger immediate cleanup of all
 * previously created threads.
 * @see philo_routine()
 */
static bool	create_all_threads(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine, \
	&data->philos[i]) != 0)
		{
			j = 0;
			while (j < i)
			{
				pthread_join(data->philos[j].thread, NULL);
				j++;
			}
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * @brief Waits for all philosopher threads and optionally the monitor
 * to terminate.
 * This function performs the necessary joins to ensure all threads have
 * completed their execution before the main program continues.
 * @param data Pointer to the main simulation data structure.
 * @param join_monitor If true, also joins the monitor thread.
 * @note Joins all philosopher threads in the order they were created.
 * @note Only joins the monitor thread if join_monitor is true and the
 * monitor thread exists.
 * @note This function blocks until all specified threads have terminated.
 */
static void	join_all_threads(t_data *data, bool join_monitor)
{
	size_t	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	if (join_monitor)
		pthread_join(data->monitor, NULL);
}

/**
 * @brief Creates the monitor thread that supervises the simulation.
 * The monitor thread is responsible for checking philosopher states,
 * detecting deaths, and terminating the simulation when necessary.
 * @param data Pointer to the main simulation data structure.
 * @return bool true if the monitor thread is successfully created,
 * false otherwise.
 * @note If monitor creation fails, it sets the death flag to terminate
 * all philosopher threads and joins them immediately.
 * @note The monitor runs monitor_routine and has access to all simulation data.
 * @warning On creation failure, triggers immediate simulation termination
 * by setting philo_died flag and joining all philosopher threads.
 * @warning The death_lock mutex must be held when modifying philo_died.
 * @see monitor_routine()
 */
static bool	create_monitor(t_data *data)
{
	if (pthread_create(&data->monitor, NULL, &monitor_routine, data) != 0)
	{
		join_all_threads(data, false);
		return (false);
	}
	return (true);
}

/**
 * @brief Main function that starts and manages the entire dining simulation.
 * This function orchestrates the complete dinner simulation by:
 * 1. Setting initial timing for all philosophers
 * 2. Creating all philosopher threads
 * 3. Creating the monitor thread
 * 4. Waiting for all threads to complete
 * @param data Pointer to the fully initialized simulation data structure.
 * @return bool true if the simulation starts and completes successfully,
 * false if thread creation fails at any stage.
 * @note The simulation runs until a philosopher dies or all philosophers
 * reach the required meal count (if specified).
 * @note Implements comprehensive error handling with proper cleanup at
 * each failure point.
 * @see set_time_dinner()
 * @see create_all_threads()
 * @see create_monitor()
 * @see join_all_threads()
 */
bool	start_dinner(t_data *data)
{
	set_time_dinner(data);
	if (!create_all_threads(data))
		return (false);
	if (!create_monitor(data))
		return (false);
	join_all_threads(data, true);
	return (true);
}
