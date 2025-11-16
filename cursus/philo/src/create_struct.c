/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:49:31 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 01:53:29 by sergio           ###   ########.fr       */
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
 * This static function initializes the two main mutexes used for
 * synchronizing global state:
 * - **write_lock**: Protects log output to prevent interleaved messages
 * @ref print_status.
 * - **death_lock**: Protects access to the global `philo_died` flag
 * @ref check_death.
 * @param data Pointer to the main simulation data structure.
 * @return bool true if all mutexes are successfully initialized,
 * false otherwise.
 * @note If any mutex initialization fails, all previously initialized
 * mutexes are properly destroyed before returning.
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
 * This function performs two steps:
 * 1. Allocates memory for `n_philos` mutexes using `ft_calloc`.
 * 2. Calls @ref fill_forks to initialize each individual mutex in the array.
 * @param data Pointer to the main simulation data structure.
 * @return static t_mutex* Pointer to the allocated array of fork mutexes
 * on success, or **NULL** if allocation or initialization fails.
 * @note If initialization fails, the allocated memory for `data->forks`
 * is freed.
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
 * of philosopher structures and the fork resources they need.
 * The internal flow is:
 * 1. Allocate memory for the `t_philo` array.
 * 2. Call @ref init_forks to allocate and initialize the fork mutexes.
 * 3. Call @ref fill_philos to set each philosopher's initial state
 * (ID, pointers, etc.).
 * @param data Pointer to the main simulation data structure.
 * @return static t_philo* Pointer to the newly allocated and initialized
 * philosopher array on success, or **NULL** if memory allocation or resource
 * initialization fails.
 * @note Contains complex cleanup logic to handle resource dependencies.
 * @see fill_philos()
 */
static t_philo	*init_philos(t_data *data)
{
	data->philos = ft_calloc(data->n_philos, sizeof(t_philo));
	if (!data->philos)
		return (NULL);
	data->forks = init_forks(data);
	if (!data->forks)
		return (free(data->philos), NULL);
	if (!fill_philos(data, data->philos))
		return (free(data->philos), free(data->forks), NULL);
	return (data->philos);
}

/**
 * @brief Main initialization routine for the simulation data structure.
 * This function orchestrates the complete setup sequence:
 * 1. Allocate main @ref t_data structure.
 * 2. Validate command-line arguments @ref check_arguments.
 * 3. Parse and fill simulation parameters @ref fill_data.
 * 4. Initialize global mutexes @ref init_mutex_data.
 * 5. Allocate and initialize philosophers, forks, and local mutexes
 * @ref init_philos.
 * @param argv The array of command-line argument strings.
 * @return t_data* Pointer to the fully initialized simulation data structure,
 * or **NULL** if any initialization step fails.
 * @note Implements a cascade of error handling: on failure, only the resources
 * allocated in preceding steps that were *successful* are cleaned up.
 * @warning The caller (`main.c`) is responsible for calling @ref final_clean
 * on the returned pointer if initialization is successful.
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
	return (data);
}
