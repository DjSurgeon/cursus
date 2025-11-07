/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:14:12 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/07 18:25:25 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}

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

long long	get_timestamp(long long start)
{
	return (get_time() - start);
}
