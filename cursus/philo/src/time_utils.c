/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:14:12 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/07 23:06:05 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file time_utils.c
 * @brief Utility functions for precise time management and custom delays
 * in the Philosophers simulation.
 * This module provides functions to retrieve the current time in milliseconds
 * and a custom sleep routine that attempts to maintain better accuracy for
 * short delays than standard `usleep` alone.
 */
#include "philo.h"

/**
 * @brief Retrieves the current time with millisecond precision.
 * Uses the system function `gettimeofday` to obtain the time since the Epoch
 * (January 1, 1970) and converts the result into a single `long long` value
 * representing milliseconds.
 * @return long long The current time in milliseconds (ms).
 * @note This function is the primary source of time data for the entire
 * simulation.
 */
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}

/**
 * @brief Custom microsecond sleep function for millisecond accuracy.
 * Implements a time-checking loop to pause execution for approximately
 * `ms` milliseconds. It uses a hybrid approach to balance precision
 * and CPU usage:
 * - For very short delays (<= 5ms), it uses **busy waiting** (an empty
 * `while` loop) to minimize thread scheduling overhead and maintain
 * high precision.
 * - For longer delays, it repeatedly calls the system function
 * `usleep(100)` inside a time-checking loop, which is more efficient
 * for the CPU but slightly less accurate than pure busy waiting.
 * @param ms The time to pause the thread execution, in milliseconds.
 * @note The constant `100` in `usleep(100)` represents 100 microseconds
 * (0.1ms), which is a trade-off chosen for granularity.
 * @warning Busy waiting for long periods (ms > 5) will consume excessive
 * CPU resources.
 * This function optimizes for the short, critical delays typical in
 * this project.
 */
void	ft_usleep(long long ms)
{
	long long	start;

	start = get_time();
	if (ms <= 5)
	{
		while (get_time() - start < ms)
			;
	}
	else
	{
		while (get_time() - start < ms)
		{
			usleep(100);
		}
	}
}

/**
 * @brief Calculates the elapsed time since a given starting point.
 * Subtracts a starting timestamp (`start`) from the current time
 * (obtained via @ref get_time) to determine the duration that has
 * passed since that event.
 * @param start The starting timestamp (in milliseconds). This is
 * typically the simulation start time or the last meal time.
 * @return long long The elapsed time in milliseconds.
 */
long long	get_timestamp(long long start)
{
	return (get_time() - start);
}
