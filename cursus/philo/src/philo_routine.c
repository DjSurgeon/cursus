/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 02:06:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 23:41:49 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_routine.c
 * @brief Implementation of specific philosopher behaviors and actions.
 * This file contains the detailed implementations of individual philosopher
 * actions: thinking, eating, sleeping, and fork management. These functions
 * are called by the main philosopher routine to execute specific behaviors
 * with proper synchronization and timing.
 * @note All functions include proper state logging and timing control.
 * @warning Fork operations must maintain consistent locking order to prevent
 * deadlocks between philosophers.
 */
#include "philo.h"

/**
 * @brief Executes the thinking behavior for a philosopher.
 * The philosopher logs their thinking status. In this simulation model,
 * thinking often represents a state between sleeping and trying to eat.
 * @param philo Pointer to the philosopher's individual data structure.
 * @note This state is typically instantaneous as the philosopher immediately
 * attempts to acquire forks after logging the status.
 * @see print_status()
 */
void	philo_think(t_philo *philo)
{
	print_status(philo, THINK);
}

/**
 * @brief Executes the sleeping behavior for a philosopher.
 * The philosopher logs the sleep status and then suspends execution
 * for the duration of `time_to_sleep`.
 * @param philo Pointer to the philosopher's individual data structure.
 * @note Uses @ref ft_usleep() for precise timing control during sleep.
 * @note The sleep duration is controlled by `data->tt_sleep`.
 * @warning The philosopher is inactive during this time and relies on the
 * monitor thread to detect any starvation.
 * @see print_status()
 * @see ft_usleep()
 */
void	philo_sleep(t_philo *philo)
{
	print_status(philo, SLEEP);
	ft_usleep(philo->data->tt_sleep);
}

/**
 * @brief Executes the eating behavior for a philosopher.
 * This is a **critical section** where the philosopher holds both forks.
 * During eating, shared state variables are updated under lock protection.
 * @param philo Pointer to the philosopher's individual data structure.
 * @note **Synchronization**: The update of `last_meal` and `meals` is
 * protected by `philo->meal_lock` to ensure thread safety against the
 * monitor thread, which reads these values.
 * @note The `last_meal` update is crucial for the monitor's starvation
 * detection.
 * @see print_status()
 * @see get_time()
 * @see ft_usleep()
 */
void	philo_eat(t_philo *philo)
{
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->meal_lock);
	philo->meals++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->data->tt_eat);
}

/**
 * @brief Releases both forks held by a philosopher.
 * This function unlocks the mutexes representing the forks in the
 * **reverse order** of acquisition to maintain consistency and discipline
 * in locking.
 * @param philo Pointer to the philosopher's individual data structure.
 * @note **Order Consistency**: The unlock order is swapped based on the
 * philosopher's ID to match the required reverse order of acquisition
 * (e.g., if acquisition was L then R, drop must be R then L).
 * @warning The unlock order must be strictly the reverse of the lock order
 * used in @ref take_forks() to prevent logical errors and resource
 * contention issues.
 * @see take_forks()
 */
void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}
