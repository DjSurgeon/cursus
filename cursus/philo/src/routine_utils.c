/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:36:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 23:28:04 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file routine_utils.c
 * @brief Utility functions supporting philosopher routines and simulation
 * management.
 * This file contains helper functions for special cases, status reporting,
 * and death checking that are used throughout the philosopher routines.
 * @note Implements thread-safe operations with proper synchronization.
 */
#include "philo.h"

/**
 * @brief Special routine for simulations with only one philosopher.
 * This function handles the edge case where there is only one philosopher
 * at the table. Since there's only one fork available, the philosopher
 * cannot eat (requires two forks) and will eventually die from starvation.
 * The routine:
 * 1. Logs that the philosopher picks up the single available fork
 * 2. Waits for the time_to_die duration
 * 3. The philosopher dies without ever eating
 * @param philo Pointer to the philosopher's individual data structure.
 * @note This is a terminal routine - the philosopher thread will exit
 * after completing this function.
 * @note The philosopher never gets to eat because there's no second fork.
 * @note The death will be detected by the monitor thread after tt_die ms.
 * @see print_status()
 * @see ft_usleep()
 */
void	one_philo_routine(t_philo *philo)
{
	print_status(philo, FORK);
	ft_usleep(philo->data->tt_die);
}

/**
 * @brief Thread-safe function for printing philosopher status messages.
 * This function safely logs philosopher state changes to stdout while
 * preventing interleaved output from multiple threads. It ensures that:
 * - Messages are not printed after simulation termination (death detected)
 * - Output from different philosophers doesn't get mixed together
 * - Timestamps are calculated relative to simulation start
 * @param philo Pointer to the philosopher's individual data structure.
 * @param str String describing the philosopher's current state/action.
 * Expected values: "is thinking", "is eating", "is sleeping", 
 * "has taken a fork", "died"
 * @note Checks for death condition twice: before and during lock acquisition
 * to ensure no messages are printed after simulation termination.
 * @note Uses write_lock mutex to ensure atomic output operations.
 * @note Calculates relative timestamp from simulation start for
 * accurate logging.
 * @warning This function should be used for all simulation output to maintain
 * consistency and prevent race conditions in log messages.
 * @see check_death()
 * @see get_time()
 */
void	print_status(t_philo *philo, char *str)
{
	long long	timestamp;

	if (check_death(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->write_lock);
	if (!check_death(philo->data))
	{
		timestamp = get_time() - philo->data->start_t;
		printf("[%lldms] - [philo: %zu] \"%s\"\n", timestamp, philo->id, str);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

/**
 * @brief Safely checks if the simulation should terminate due to a
 * philosopher's death.
 * This function provides thread-safe access to the global death flag that
 * indicates whether any philosopher has died and the simulation should end.
 * It uses the death_lock mutex to ensure atomic read operations on the
 * philo_died flag.
 * @param data Pointer to the main simulation data structure.
 * @return bool true if a philosopher has died and simulation should terminate,
 * false otherwise.
 * @note This function should be called frequently in philosopher routines
 * to ensure quick termination when death occurs.
 * @note The death_lock mutex protects against race conditions when multiple
 * threads check the death flag simultaneously.
 * @note The monitor thread is responsible for setting the philo_died flag
 * when death conditions are detected.
 * @warning This function provides a consistent view of the death state
 * but doesn't prevent the "check-then-act" race condition on its own.
 * @warning Callers should use additional synchronization if they need to
 * perform multiple operations based on the death state.
 */
bool	check_death(t_data *data)
{
	bool	dead;

	dead = false;
	pthread_mutex_lock(&data->death_lock);
	if (data->philo_died == 1)
		dead = true;
	pthread_mutex_unlock(&data->death_lock);
	return (dead);
}

void	set_death(t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	data->philo_died = 1;
	pthread_mutex_unlock(&data->death_lock);
}

bool	philos_stop(t_philo *philo)
{
	if (philo->data->eat_count == -1)
		return (false);
	pthread_mutex_lock(&philo->meal_lock);
	if (philo->meals == (size_t)philo->data->eat_count)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->meal_lock);
	return (false);
}
