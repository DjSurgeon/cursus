/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:49:31 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 15:14:40 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create_struct.c
 * @brief Contains functions responsible for allocating and initializing the
 * main simulation data structure @ref t_data and the array of philosophers
 * @ref t_philo, and all required synchronization primitives (mutexes).
 * This module coordinates memory allocation, argument parsing, and initial
 * state setup before the simulation threads are created.
 * @note Implements robust error handling with proper cleanup at each stage.
 * @warning All mutex initialization failures trigger immediate cleanup.
 */
#include "philo.h"

/**
 * @brief Initializes the global mutexes for the simulation.
 * This static function initializes the three main mutexes used for
 * synchronizing different aspects of the simulation:
 * - write_lock: Protects log output to prevent interleaved messages
 * - death_lock: Protects access to the philo_died flag
 * - meal_lock: Protects access to meal-related data (last_meal, meals)
 * @param data Pointer to the main simulation data structure.
 * @return bool true if all mutexes are successfully initialized,
 * false otherwise.
 * @note If any mutex initialization fails, all previously initialized
 * mutexes are properly destroyed before returning.
 * @warning Mutex initialization order is important for proper cleanup
 * on failure.
 */
static bool	init_mutex_data(t_data *data)
{
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->death_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write_lock);
		return (false);
	}
	return (true);
}

/**
 * @brief Allocates and initializes the array of fork mutexes.
 * This function creates the array of mutexes that represent the forks
 * on the table. Each philosopher will need to acquire two forks (mutexes)
 * to be able to eat.
 * @param data Pointer to the main simulation data structure.
 * @return t_mutex* Pointer to the allocated array of fork mutexes,
 * or NULL if allocation or initialization fails.
 * @note The number of forks equals the number of philosophers.
 * @note Uses ft_calloc for allocation, ensuring zero-initialization.
 * @note Calls fill_forks() to initialize each individual mutex in the array.
 * @warning If fork initialization fails, the entire forks array is freed.
 * @warning The caller must handle cleanup of the forks array on failure.
 * @see fill_forks()
 */
static t_mutex	*init_forks(t_data *data)
{
	data->forks = ft_calloc(data->n_philos, sizeof(t_mutex));
	if (!data->forks)
		return (NULL);
	if (!fill_forks(data, data->forks))
		return (free(data->forks), NULL);
	return (data->forks);
}

/**
 * @brief Allocates and initializes the array of philosopher structures.
 * This static helper function is responsible for creating the array
 * of philosopher structures that will be used in the simulation.
 * @param data Pointer to the main simulation data structure.
 * @return t_philo* Pointer to the newly allocated and initialized
 * philosopher array on success, or NULL if memory allocation fails.
 * @note Allocates memory for all philosophers based on data->n_philos.
 * @note Calls fill_philos() to initialize each philosopher's initial state.
 * @note If initialization fails, the allocated memory is freed before returning.
 * @warning The philosopher array must be properly freed on simulation end.
 * @warning Returns NULL if allocation or initialization fails.
 * @see fill_philos()
 */
static t_philo	*init_philos(t_data *data)
{
	data->philos = ft_calloc(data->n_philos, sizeof(t_philo));
	if (!data->philos)
		return (NULL);
	if (!fill_philos(data, data->philos))
		return (free(data->philos), NULL);
	return (data->philos);
}

/**
 * @brief Main initialization routine for the simulation data structure.
 * This function orchestrates the complete setup sequence for the simulation
 * by performing all necessary allocations and initializations in the
 * correct order:
 * 1. Allocate main data structure
 * 2. Validate command-line arguments
 * 3. Parse and fill simulation parameters
 * 4. Initialize global mutexes
 * 5. Allocate and initialize forks
 * 6. Allocate and initialize philosophers
 * @param argv The array of command-line argument strings.
 * @return t_data* Pointer to the fully initialized simulation data structure,
 * or NULL if any initialization step fails. 
 * @note Implements comprehensive error handling with proper cleanup cascade.
 * @note Each initialization failure triggers cleanup of all previously
 * allocated resources.
 * @note The caller is responsible for calling the appropriate cleanup
 * function on the returned pointer.
 * @warning If this function returns NULL, no cleanup is needed as all
 * resources have already been freed.
 * @warning If this function returns a valid pointer, the caller must
 * ensure proper cleanup using final_clean().
 */
t_data	*init_data(char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	if (!check_arguments(argv))
		return (free(data), NULL);
	data = fill_data(argv, data);
	if (!init_mutex_data(data))
		return (free(data), NULL);
	data->philos = init_philos(data);
	if (!data->philos)
		return (clean_mutex_data(data), free(data), NULL);
	data->forks = init_forks(data);
	if (!data->forks)	
		return (clean_mutex_data(data), free(data->forks), free(data), NULL);
	return (data);
}
