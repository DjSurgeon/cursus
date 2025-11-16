/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:07:44 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 23:51:18 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_routine2.c
 * @brief Fork acquisition functions for philosopher routines.
 * This file contains the implementation of fork acquisition logic with
 * proper deadlock prevention and simulation termination checking.
 * @note Implements a specific asymmetrical locking strategy to prevent
 * the circular wait condition that leads to deadlock.
 * @warning Fork acquisition order is critical. The logic handles the last
 * philosopher (ID = N) as the odd one out to break the cycle.
 */
#include "philo.h"

/**
 * @brief Attempts to acquire both the left and right forks for the philosopher.
 * This function implements the core strategy to prevent a circular
 * wait deadlock.
 * It defines a non-symmetrical locking order for the last philosopher
 * (ID == N) compared to all others.
 * @param philo Pointer to the philosopher's individual data structure.
 * @return bool **true** if both forks are successfully acquired, **false** if
 * the simulation terminated (a philosopher died) before or during the
 * acquisition.
 * @note **Deadlock Prevention**:
 * - **Philosopher N (the last one)**: Locks the **Right** fork first, then
 * the **Left** fork.
 * - **All Other Philosophers**: Lock the **Left** fork first, then the
 * **Right** fork.
 * This asymmetry ensures that not all philosophers can simultaneously
 * hold their first fork and wait for their second, breaking the circular wait.
 * @note **Termination Check**: Checks for the death flag immediately before the
 * first lock, and again before the second lock. If death is detected between
 * the two lock attempts, the philosopher releases the single held fork
 * and exits.
 * @see check_death()
 * @see print_status()
 */
bool	take_forks(t_philo *philo)
{
	t_mutex	*first;
	t_mutex	*second;

	if (check_death(philo->data))
		return (false);
	if (philo->id == philo->data->n_philos)
	{
		first = philo->r_fork;
		second = philo->l_fork;
	}
	else
	{
		first = philo->l_fork;
		second = philo->r_fork;
	}
	pthread_mutex_lock(first);
	print_status(philo, FORK);
	if (check_death(philo->data))
	{
		pthread_mutex_unlock(first);
		return (false);
	}
	pthread_mutex_lock(second);
	print_status(philo, FORK);
	return (true);
}
