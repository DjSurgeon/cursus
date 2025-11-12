/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:26:01 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/12 11:28:22 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file fill_struct.c
 * @brief Contains helper functions responsible for transferring validated
 * command-line arguments into the main simulation data structures.
 * This file implements the parsing logic for @ref t_data and the initial
 * state assignment for the array of @ref t_philo structures.
 */
#include "philo.h"

/**
 * @brief Parses validated command-line arguments and fills the global
 * parameters of the @ref t_data structure.
 * This function is called after argument validation (@ref check_arguments)
 * and assumes all elements in `argv` are numeric and within required limits.
 * It uses @ref ft_atoi to convert the string arguments into their
 * corresponding `size_t` fields.
 * @param argv The array of command-line argument strings.
 * @param data Pointer to the pre-allocated @ref t_data structure.
 * @return t_data* Returns the pointer to the modified @ref t_data structure
 * on success.
 * @note The optional argument `argv[5]` (eat_count) is handled by setting
 * `data->eat_count` to **0** if the argument is not provided, allowing the
 * simulation to run until a philosopher dies.
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
	data->philo_died = false;
	data->start_t = get_time();
	return (data);
}

/**
 * @brief Initializes the individual state variables for each philosopher.
 * This function iterates through the allocated array `data->philos`
 * (from index 0 up to `data->n_philos - 1`) and sets the initial state
 * for each @ref t_philo structure before thread creation.
 * It is assumed that `data->philos` has been successfully allocated prior
 * to this call.
 * The initial state includes:
 * - **id**: Unique identifier (set from 1 to N, where N is `data->n_philos`).
 * - **meals**: Counter initialized to 0.
 * - **last_meal**: Initialized to 0.
 * - **start_t**: Initialized to 0.
 * @param data Pointer to the main @ref t_data structure containing the allocated
 * `data->philos` array and `n_philos` count.
 * @return t_data* Returns the pointer to the modified @ref t_data structure
 * on success.
 * @warning The fields `last_meal` and `start_t` are initialized to 0 here
 * but MUST be set to the actual simulation start timestamp (via @ref get_time)
 * immediately before launching the philosopher threads to ensure correct timing.
 */
bool	fill_philos(t_data *data)
{
	size_t	i;

	i = 0;
	if (!data || !data->philos)
		return (false);
	while (i < data->n_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals = 0;
		data->philos[i].last_meal = data->start_t;
		data->philos[i].l_forks = &data->forks[i];
		data->philos[i].r_forks = &data->forks[(i + 1) % data->n_philos];
		data->philos[i].data = data;
		i++;
	}
	return (true);
}

bool	fill_forks(t_data *data)
{
	size_t	i;

	i = 0;
	if (!data || !data->forks)
		return (false);
	while (i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (true);
}
