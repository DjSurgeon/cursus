/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:26:01 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 20:49:53 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file fill_struct.c
 * @brief Contains helper functions responsible for transferring validated
 * command-line arguments into the main simulation data structures.
 * This file implements the parsing logic for @ref t_data and the initial
 * state assignment for the array of @ref t_philo structures, and initializes
 * all dynamically allocated mutexes (forks and meal locks).
 * @note All functions assume pre-validated input and pre-allocated structures.
 */
#include "philo.h"

/**
 * @brief Parses validated command-line arguments and fills the global
 * parameters of the @ref t_data structure.
 * This function converts string arguments to numeric values and initializes
 * the main simulation parameters. It's called after successful argument
 * validation and assumes all inputs are valid numeric strings.
 * @param argv The array of command-line argument strings.
 * @param data Pointer to the pre-allocated @ref t_data structure.
 * @return t_data* Returns the pointer to the modified data structure.
 * @note The optional eat_count is set to -1 if not provided, indicating
 * no minimum meal requirement.
 * @see ft_atoi()
 */
t_data	*fill_data(char **argv, t_data *data)
{
	data->n_philos = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->eat_count = ft_atoi(argv[5]);
	else
		data->eat_count = -1;
	data->philos = NULL;
	data->forks = NULL;
	data->philo_died = 0;
	data->start_t = 0;
	data->monitor = 0;
	return (data);
}

/**
 * @brief Initializes the individual state variables for each philosopher.
 * This function sets up the initial state for all philosophers in the
 * simulation, including their IDs, meal counts, and assigns pointers
 * to the fork mutexes.
 * @param data Pointer to the main simulation data structure.
 * @param philos Pointer to the pre-allocated array of philosopher structures.
 * @return bool Returns **true** if all philosophers are successfully
 * initialized.
 * @note Philosopher IDs are assigned from 1 to `n_philos`.
 * @note **Circular Fork Assignment**: Philosopher `i` gets fork `i` (left)
 * and fork `(i + 1) % n_philos` (right).
 */
bool	fill_philos(t_data *data, t_philo *philos)
{
	size_t	i;

	i = 0;
	if (!data || !philos)
		return (false);
	while (i < data->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals = 0;
		philos[i].last_meal = 0;
		philos[i].l_fork = &data->forks[i];
		philos[i].r_fork = &data->forks[(i + 1) % data->n_philos];
		philos[i].thread = 0;
		philos[i].data = data;
		i++;
	}
	return (true);
}

/**
 * @brief Initializes the local meal mutexes for all philosophers.
 * This function initializes the `meal_lock` (`t_philo::meal_lock`) for
 * each philosopher.
 * This mutex protects concurrent access to the `meals` count and `last_meal`
 * timestamp.
 * @param data Pointer to the main data structure.
 * @return static bool Returns **true** if all mutexes are initialized
 * successfully.
 * @note **Cascading Cleanup**: If initialization fails at index `j`, the
 * function destroys all successfully initialized meal mutexes up to `j`,
 * and then calls @ref clean_mutex_forks to destroy the entire array of
 * fork mutexes before returning **false**.
 * @see clean_mutex_meal()
 * @see clean_mutex_forks()
 */
static bool	mutex_meals(t_data *data)
{
	size_t	j;

	j = 0;
	while (j < data->n_philos)
	{
		if (pthread_mutex_init(&data->philos[j].meal_lock, NULL) == 0)
			j++;
		else
		{
			clean_mutex_meal(data->philos, j);
			clean_mutex_forks(data->forks, data->n_philos);
			return (false);
		}
	}
	return (true);
}

/**
 * @brief Initializes the global array of fork mutexes.
 * This function initializes each mutex in the `data->forks` array.
 * @param data Pointer to the main data structure.
 * @return static bool Returns **true** if all fork mutexes are initialized
 * successfully.
 * @note **Cascading Cleanup**: If initialization fails at index `i`, the
 * function calls @ref clean_mutex_forks to destroy the `i` mutexes that
 * were successfully initialized before returning **false**.
 * @see clean_mutex_forks()
 */
static bool	mutex_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) == 0)
			i++;
		else
		{
			clean_mutex_forks(data->forks, i);
			return (false);
		}
	}
	return (true);
}

/**
 * @brief Orchestrates the initialization of all dynamically allocated mutexes.
 * This function is the primary interface for initializing the two groups of
 * dynamic mutexes: forks (shared global mutexes) and meal locks (local
 * philosopher mutexes).
 * @param data Pointer to the main data structure.
 * @param forks Pointer to the pre-allocated array of fork mutexes.
 * @return bool Returns **true** if both types of mutexes are initialized
 * successfully. Returns **false** if any step fails (cleanup is handled
 * internally by helper functions).
 */
bool	fill_forks(t_data *data, t_mutex *forks)
{
	if (!data || !forks)
		return (false);
	if (!mutex_forks(data))
		return (false);
	if (!mutex_meals(data))
		return (false);
	return (true);
}
