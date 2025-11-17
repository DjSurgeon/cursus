/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:46:43 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/17 10:22:34 by serjimen         ###   ########.fr       */
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
 * This function sets the global simulation start time (`data->start_t`) and
 * initializes the last meal time for every philosopher to this same start time,
 * ensuring consistent timing measurements from the very beginning.
 * @param data Pointer to the main simulation data structure.
 * @note Uses @ref get_time() to retrieve the current timestamp.
 * @warning Must be called immediately before thread creation to ensure
 * accurate death monitoring.
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
 * This function attempts to create one thread for each philosopher using the
 * @ref philo_routine function. It implements a critical **rollback cleanup**
 * mechanism.
 * @param data Pointer to the main simulation data structure.
 * @return bool **true** if all threads are successfully created, **false**
 * if any thread creation fails.
 * @note **Rollback on Failure**: If thread creation fails at index `i`,
 * the function immediately stops, and properly joins (`pthread_join`) all
 * threads from 0 to `i-1` that were successfully created before
 * returning `false`.
 * @see philo_routine()
 * @see pthread_create()
 */
static bool	create_all_threads(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&philo_routine, &data->philos[i]) != 0)
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
	ft_usleep(100);
	return (true);
}

/**
 * @brief Waits for all philosopher threads and optionally the monitor
 * thread to terminate.
 * This function blocks the main thread until all specified threads have
 * completed their execution using `pthread_join`.
 * @param data Pointer to the main simulation data structure.
 * @param join_monitor If **true**, the monitor thread (`data->monitor`)
 * is also joined.
 * @note Ensures a clean exit by guaranteeing no threads are left running.
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
 * detecting death, and checking the termination condition (all meals eaten).
 * @param data Pointer to the main simulation data structure.
 * @return bool **true** if the monitor thread is successfully created,
 * **false** otherwise.
 * @note **Failure Handling**: If monitor creation fails, it immediately calls
 * @ref join_all_threads (with `join_monitor = false`) to clean up all
 * philosopher threads before returning, ensuring that the main function can
 * proceed with memory cleanup.
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
 * This function orchestrates the complete dinner simulation lifecycle:
 * 1. Initialize timing.
 * 2. Create philosopher threads (with rollback on failure).
 * 3. Create the monitor thread (with cleanup on failure).
 * 4. Wait for all threads (philosophers and monitor) to finish.
 * @param data Pointer to the fully initialized simulation data structure.
 * @return bool **true** if the simulation starts and completes successfully,
 * **false** if thread creation fails at any stage.
 * @note This is the final step before the main thread calls @ref final_clean.
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
