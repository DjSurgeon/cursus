/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 02:06:24 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 17:40:17 by sergio-jime      ###   ########.fr       */
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
 * This function represents the philosopher's thinking state. The philosopher
 * will log their thinking status and then proceed to the next action.
 * @param philo Pointer to the philosopher's individual data structure.
 * @note Thinking is typically an instantaneous action in this simulation
 * as philosophers immediately try to acquire forks after thinking.
 * @note The thinking state is logged for simulation tracking.
 * @see print_status()
 */
void	philo_think(t_philo *philo)
{
	print_status(philo, THINK);
}

/**
 * @brief Executes the sleeping behavior for a philosopher.
 * This function puts the philosopher to sleep for the specified time
 * after eating. The philosopher logs the sleep status and then suspends
 * execution for the duration of time_to_sleep.
 * @param philo Pointer to the philosopher's individual data structure.
 * @note Uses ft_usleep() for precise timing control during sleep.
 * @note The sleep duration is controlled by data->tt_sleep parameter.
 * @note Sleep state is logged before the actual sleep begins.
 * @warning During sleep, the philosopher cannot check for death conditions.
 * The monitor thread is responsible for detecting deaths during this period.
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
 * This function represents the philosopher's eating state. The philosopher
 * must already hold both forks before calling this function. During eating:
 * - Logs the eating status
 * - Updates the last meal timestamp (protected by meal_lock)
 * - Increments the meal counter (protected by meal_lock)
 * - Sleeps for the duration of time_to_eat
 * @param philo Pointer to the philosopher's individual data structure.
 * @note The last_meal update is critical for starvation detection by
 * the monitor.
 * @note Meal counter increment is used to track progress toward eat_count goal.
 * @note Both last_meal and meals are protected by meal_lock for thread safety.
 * @see print_status()
 * @see get_time()
 * @see ft_usleep()
 */
void	philo_eat(t_philo *philo)
{
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->meal_lock);
	// philo->last_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->data->tt_eat);
}

/**
 * @brief Releases both forks held by a philosopher.
 * This function unlocks the mutexes representing the forks that the
 * philosopher was using during eating. The unlock order varies based
 * on philosopher ID to maintain consistent locking order and prevent
 * deadlocks across the entire system.
 * @param philo Pointer to the philosopher's individual data structure.
 * @note Even-numbered philosophers: unlock left fork then right fork
 * @note Odd-numbered philosophers: unlock right fork then left fork
 * @note This reverse order from acquisition helps prevent resource
 * contention and maintains locking consistency.
 * @warning The unlock order must be the reverse of the acquisition order
 * used in take_forks() to maintain proper locking discipline.
 * @warning Philosophers must hold both forks before calling this function.
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
