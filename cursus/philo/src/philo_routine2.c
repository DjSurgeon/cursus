/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:07:44 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/14 14:12:22 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_routine2.c
 * @brief Fork acquisition functions for philosopher routines.
 * This file contains the implementation of fork acquisition logic with
 * proper deadlock prevention and simulation termination checking.
 * The functions implement different locking strategies for odd and even
 * philosophers to prevent circular wait conditions.
 * @note Implements robust error handling with proper cleanup on failure.
 * @warning Fork acquisition order is critical for deadlock prevention.
 */
#include "philo.h"

/**
 * @brief Fork acquisition strategy for odd-numbered philosophers.
 * This function implements the fork acquisition sequence for philosophers
 * with odd IDs (1, 3, 5, ...). The locking order is:
 * 1. Left fork first
 * 2. Right fork second
 * After acquiring each fork, the function checks if the simulation should
 * terminate due to a philosopher's death. If death is detected at any point,
 * all acquired forks are immediately released and the function returns false.
 * @param philo Pointer to the philosopher's individual data structure.
 * @return bool true if both forks are successfully acquired, false if
 * simulation termination is detected or acquisition fails.
 * @note Logs fork acquisition for each successfully taken fork.
 * @note Implements immediate cleanup on death detection to prevent
 * philosophers from holding forks after simulation termination.
 * @warning Death checking after each acquisition ensures quick termination.
 * @see check_death()
 * @see print_status()
 */
static bool	is_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (check_death(philo->data))
	{
		pthread_mutex_unlock(philo->l_fork);
		return (false);
	}
	print_status(philo, FORK);
	pthread_mutex_lock(philo->r_fork);
	if (check_death(philo->data))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (false);
	}
	print_status(philo, FORK);
	return (true);
}

/**
 * @brief Fork acquisition strategy for even-numbered philosophers.
 * This function implements the fork acquisition sequence for philosophers
 * with even IDs (2, 4, 6, ...). The locking order is:
 * 1. Right fork first
 * 2. Left fork second
 * This reverse order compared to odd philosophers prevents the circular
 * wait condition that leads to deadlocks. After acquiring each fork,
 * the function checks for simulation termination and releases all
 * acquired resources if death is detected.
 * @param philo Pointer to the philosopher's individual data structure.
 * @return bool true if both forks are successfully acquired, false if
 * simulation termination is detected or acquisition fails.
 * @note The different acquisition order for even vs odd philosophers
 * is a classic solution to the dining philosophers deadlock problem.
 * @note Ensures proper resource cleanup on partial acquisition failure.
 * @warning The locking order (right then left) must be consistent across
 * all even-numbered philosophers.
 * @warning This strategy works because there's no global ordering of
 * resources that all threads must follow.
 * @see check_death()
 * @see print_status()
 */
static bool	is_even(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	if (check_death(philo->data))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (false);
	}
	print_status(philo, FORK);
	pthread_mutex_lock(philo->l_fork);
	if (check_death(philo->data))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (false);
	}
	print_status(philo, FORK);
	return (true);
}

/**
 * @brief Main fork acquisition function that delegates based on philosopher ID.
 * This function selects the appropriate fork acquisition strategy based on
 * whether the philosopher has an odd or even ID. This strategy ensures that
 * neighboring philosophers use different fork acquisition orders, preventing
 * the circular wait condition that causes deadlocks.
 * @param philo Pointer to the philosopher's individual data structure.
 * @return bool true if both forks are successfully acquired using the
 * appropriate strategy, false if acquisition fails or simulation terminates.
 * @note Odd philosophers (1, 3, 5...): acquire left fork then right fork
 * @note Even philosophers (2, 4, 6...): acquire right fork then left fork
 * @note This creates a "staggered" acquisition pattern that breaks potential
 * deadlock cycles.
 * @warning The strategy relies on consistent ID-based ordering across all
 * philosophers in the simulation.
 * @warning Returns false immediately if the selected strategy fails,
 * indicating that forks were not acquired.
 * @see is_odd()
 * @see is_even()
 */
bool	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (!is_even(philo))
			return (false);
	}
	else
	{
		if (!is_odd(philo))
			return (false);
	}
	return (true);
}
