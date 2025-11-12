/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:26:01 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/13 00:09:02 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file fill_struct.c
 * @brief Contains helper functions responsible for transferring validated
 * command-line arguments into the main simulation data structures.
 * This file implements the parsing logic for @ref t_data and the initial
 * state assignment for the array of @ref t_philo structures.
 * @note All functions assume pre-validated input and pre-allocated structures.
 * @warning These functions should only be called after successful allocation
 * and argument validation.
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
 * @note Initializes philo_died to false and sets the simulation start time.
 * @note Philos and forks pointers are set to NULL initially.
 * @warning Assumes argv contains valid numeric strings as verified by
 * check_arguments().
 * @see ft_atoi()
 * @see get_time()
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
 * simulation, including their IDs, meal counts, fork assignments, and
 * timing information.
 * @param data Pointer to the main simulation data structure.
 * @param philos Pointer to the pre-allocated array of philosopher structures.
 * @return bool true if all philosophers are successfully initialized,
 * false if input parameters are invalid.
 * @note Philosopher IDs are assigned from 1 to n_philos.
 * @note Forks are assigned in a circular arrangement: philosopher i gets
 * fork i (left) and fork (i+1) % n_philos (right).
 * @note Last meal time is initialized to the simulation start time.
 * @note Each philosopher stores a reference back to the main data structure.
 * @warning The forks array must be initialized before calling this function.
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
 * @brief Initializes all fork mutexes in the simulation.
 * This function initializes each mutex in the forks array, which represent
 * the forks on the table that philosophers must acquire to eat.
 * @param data Pointer to the main simulation data structure.
 * @param forks Pointer to the pre-allocated array of fork mutexes.
 * @return bool true if all mutexes are successfully initialized,
 * false if any initialization fails.
 * @note Initializes exactly data->n_philos mutexes.
 * @note If any mutex initialization fails, all previously initialized
 * mutexes are properly destroyed before returning.
 * @note Uses clean_mutex_forks() for cleanup on partial initialization failure.
 * @warning The forks array must be pre-allocated before calling this function.
 * @see clean_mutex_forks()
 */
bool	fill_forks(t_data *data, t_mutex *forks)
{
	size_t	i;

	i = 0;
	if (!data || !forks)
		return (false);
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) == 0)
			i++;
		else
		{
			clean_mutex_forks(forks, i);
			return (false);
		}
	}
	return (true);
}
