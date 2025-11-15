/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:49:43 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 15:41:48 by sergio-jime      ###   ########.fr       */
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
 * failures and normal program termination.
 * @warning All cleanup functions should be called in the correct order to
 * avoid undefined behavior.
 */
#include "philo.h"

void	clean_mutex_meal(t_philo *philo, size_t initialized)
{
	size_t	i;

	i = 0;
	while (i < initialized)
	{
		pthread_mutex_destroy(&philo->meal_lock);
		i++;
	}
}

/**
 * @brief Destroys a specified number of fork mutexes from an array.
 * This function is used for cleanup during partial initialization failures
 * where some but not all fork mutexes were successfully initialized.
 * It destroys exactly the number of mutexes that were initialized before
 * the failure occurred.
 * @param forks Pointer to the array of fork mutexes to clean up.
 * @param initialized Number of mutexes that were successfully initialized
 * and need to be destroyed.
 * @note Only destroys mutexes that were successfully initialized.
 * @note Typically used when fork initialization fails partway through.
 * @note Safe to call with initialized = 0 (no operation performed).
 * @warning Should not be called on uninitialized or already
 * destroyed mutexes.
 * @warning The forks array memory itself is not freed by this function.
 * @code
 * // Example: Cleanup after 3 out of 5 forks were initialized
 * clean_mutex_forks(forks, 3);
 * free(forks); // Then free the array memory
 * @endcode
 */
void	clean_mutex_forks(t_mutex *forks, size_t initizalized)
{
	size_t	i;

	i = 0;
	while (i < initizalized)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

/**
 * @brief Destroys the global mutexes used for simulation synchronization.
 * This function cleans up the three main global mutexes that protect
 * different aspects of the simulation:
 * @param data Pointer to the main simulation data structure containing
 * the global mutexes to be destroyed.
 * @note Destroys mutexes in an order that doesn't matter since they
 * protect different resources.
 * @note Should be called before freeing the main data structure.
 * @note Safe to call even if some mutexes were not initialized (though
 * this indicates a programming error).
 * @warning Mutexes must not be locked when destroyed (undefined behavior).
 * @warning Should ensure all threads have finished using these mutexes
 * before calling this function.
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
 * all mutexes. It handles the cleanup in the correct order:
 * 1. Destroy global mutexes
 * 2. Destroy all fork mutexes
 * 3. Free philosopher array
 * 4. Free fork array
 * 5. Free main data structure
 * @param data Pointer to the main simulation data structure to clean up.
 * @note Safe to call with NULL data (no operation performed).
 * @note Sets pointers to NULL after freeing to prevent double-free errors.
 * @note Handles partial allocation states gracefully.
 * @warning Should be called after all philosopher threads have terminated.
 * @warning Mutexes must not be locked when destroyed.
 * @warning This function should be the last operation on the data structure.
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
