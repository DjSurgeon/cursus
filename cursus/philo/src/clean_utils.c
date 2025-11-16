/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:49:43 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 21:05:02 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file clean_utils.c
 * @brief Resource cleanup and memory management functions for the
 * Philosophers simulation.
 * This file contains functions responsible for properly destroying mutexes
 * and freeing allocated memory to prevent resource leaks and ensure clean
 * program termination.
 * @note Implements safe cleanup procedures for both partial initialization
 * failures (cascading cleanup) and normal program termination.
 * @warning All cleanup functions should be called in the correct order to
 * avoid undefined behavior (e.g., freeing memory before destroying mutexes).
 */
#include "philo.h"

/**
 * @brief Destroys a specified number of local meal mutexes
 * @ref t_philo::meal_lock.
 * This function is primarily used for **cascading cleanup** when a failure
 * occurs during the initialization of the `meal_lock` array, ensuring that
 * only the mutexes that were successfully initialized are destroyed.
 * @param philo Pointer to the array of philosopher structures.
 * @param initialized The exact number of `meal_lock` mutexes that were
 * successfully initialized and need to be destroyed.
 * @note Safe to call with `initialized = 0`.
 */
void	clean_mutex_meal(t_philo *philo, size_t initialized)
{
	size_t	i;

	if (!philo)
		return ;
	i = 0;
	while (i < initialized)
	{
		pthread_mutex_destroy(&philo[i].meal_lock);
		i++;
	}
}

/**
 * @brief Destroys a specified number of fork mutexes from the
 * allocated array.
 * This function is used for cleanup during partial initialization failures
 * (like in @ref mutex_forks) where some, but not all, fork mutexes were
 * successfully initialized. It ensures that only valid, initialized mutexes
 * are destroyed.
 * @param forks Pointer to the array of fork mutexes to clean up.
 * @param initizalized Number of mutexes that were successfully initialized
 * and need to be destroyed.
 * @note Typically used when fork initialization fails partway through.
 */
void	clean_mutex_forks(t_mutex *forks, size_t initizalized)
{
	size_t	i;

	if (!forks)
		return ;
	i = 0;
	while (i < initizalized)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

/**
 * @brief Destroys the global static mutexes used for simulation
 * synchronization.
 * This function cleans up the main global mutexes stored directly within
 * the @ref t_data structure: `write_lock` and `death_lock`.
 * @param data Pointer to the main simulation data structure containing
 * the global mutexes to be destroyed.
 * @note Should be called before freeing the main data structure.
 */
void	clean_mutex_data(t_data *data)
{
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->death_lock);
}

/**
 * @brief Performs complete cleanup of all simulation resources.
 * This is the main cleanup function that should be called at program
 * termination to properly free all allocated resources and destroy
 * all mutexes. It executes cleanup in a precise, necessary order:
 * 1. Destroy global mutexes (`write_lock`, `death_lock`).
 * 2. Destroy all fork mutexes (`data->forks`).
 * 3. Destroy all philosopher meal locks (`t_philo::meal_lock`).
 * 4. Free philosopher array memory.
 * 5. Free fork array memory.
 * 6. Free main data structure memory.
 * @param data Pointer to the main simulation data structure to clean up.
 * @note Safe to call with a NULL pointer (performs a check at the start).
 * @note Handles partial allocation states gracefully by checking pointers
 * before freeing.
 */
void	final_clean(t_data *data)
{
	if (!data)
		return ;
	clean_mutex_data(data);
	clean_mutex_forks(data->forks, data->n_philos);
	clean_mutex_meal(data->philos, data->n_philos);
	if (data->philos)
		free(data->philos);
	data->philos = NULL;
	if (data->forks)
		free(data->forks);
	data->forks = NULL;
	free(data);
}
