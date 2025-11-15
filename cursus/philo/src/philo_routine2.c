/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:07:44 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 23:34:42 by sergio           ###   ########.fr       */
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
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_lock);
	return (true);
}
