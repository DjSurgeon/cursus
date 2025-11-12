/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:49:31 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/12 11:27:46 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create_struct.c
 * @brief Contains functions responsible for allocating and initializing the
 * main simulation data structure @ref t_data and the array of philosophers
 * @ref t_philo.
 * This module coordinates memory allocation, argument parsing, and initial
 * state setup before the simulation threads are created.
 */
#include "philo.h"

/**
 * 
 */
static bool	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->death_lock, NULL) != 0)
	{
		clean_mutex(data);
		return (false);
	}
	if (pthread_mutex_init(&data->meal_lock, NULL)!= 0)
	{
		clean_mutex(data);
		return (false);
	}
	return (true);
}

/**
 * 
 */
static t_mutex	*init_forks(t_mutex *forks, t_data *data)
{
	forks = ft_calloc(data->n_philos, sizeof(t_mutex));
	if (forks)
		return (NULL);
	if (!fill_forks(data))
		return (NULL);
	return (forks);
}


/**
 * @brief Allocates and initializes the array of @ref t_philo structures.
 * This static helper function is responsible for:
 * 1. **Allocation:** Dynamically allocating the required memory block for
 * all philosopher structures using @ref ft_calloc, based on `data->n_philos`.
 * 2. **Initialization:** Calling @ref fill_philos to set the initial state
 * (IDs, timestamps, meal counts) for each individual philosopher within
 * the array.
 * @param philos A pointer to a @ref t_philo structure (used as the destination
 * pointer for the allocated array).
 * @param data Pointer to the main @ref t_data structure, which must have
 * the simulation parameter `n_philos` set.
 * @return static t_philo* Returns the pointer to the newly allocated
 * and initialized @ref t_philo array on success, or **NULL** if memory
 * allocation fails.
 * @note This function is only responsible for allocating and initializing the
 * philosopher array. It returns the allocated pointer, which is then assigned
 * to `data->philos` by the caller (@ref init_data).
 */
static t_philo	*init_philos(t_philo *philos, t_data *data)
{
	philos = ft_calloc(data->n_philos, sizeof(t_philo));
	if (!data->philos)
		return (NULL);
	if (!fill_philos(data))
		return (NULL);
	return (philos);
}

/**
 * @brief Main initialization routine for the simulation data (@ref t_data).
 * This function orchestrates the complete setup sequence for the simulation:
 * 1. **Allocate** the primary @ref t_data structure.
 * 2. **Validate** command-line arguments using @ref check_arguments.
 * 3. **Parse** and fill the global parameters into `data` using
 * @ref fill_data.
 * 4. **Allocate and Initialize** the array of philosophers, assigning
 * the result to `data->philos`.
 * @param argv The array of command-line argument strings passed from main().
 * @return t_data* Pointer to the fully allocated and initialized structure,
 * or **NULL** if memory allocation fails at any stage or if arguments
 * are invalid.
 * @note **Error Handling:** This function implements robust, two-stage cleanup:
 * - If validation (`check_arguments`) fails (Step 2), the allocated `data`
 * pointer is immediately freed.
 * - If allocation/initialization of the philosopher array (`data->philos`)
 * fails (Step 4), the primary `data` structure is freed.
 * Since the `t_philo` array allocation failed, `data->philos` is never
 * assigned a valid pointer, preventing a double free.
 * @note The caller (i.e., `main`) is solely responsible for calling
 * `free(data)` if the function succeeds.
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
	if (!init_mutex(data))
		return (free(data), NULL);
	data->forks = init_forks(data->forks, data);
	if (!data->forks)
		return (free(data), NULL);
	data->philos = init_philos(data->philos, data);
	if (!data->philos)
		return (free(data->forks), free(data), NULL);
	return (data);
}
