/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:24:04 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/15 17:23:11 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* bool	check_tt_die(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (get_time() - data->philos[i].last_meal >= (long long)data->tt_die)
		{
			print_status(&data->philos[i], DIE);
			set_death(data);
			pthread_mutex_unlock(&data->philos[i].meal_lock);
			return (true);
		}
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		i++;
	}
	return (false);
} */

bool check_tt_die(t_data *data)
{
    size_t      i;
    long long   current_time;
    long long   last_meal;
    long long   time_since_meal;
    
    current_time = get_time();
    
    i = 0;
    while (i < data->n_philos)
    {
        pthread_mutex_lock(&data->philos[i].meal_lock);  // ✅ [i] no ->
        last_meal = data->philos[i].last_meal;
        pthread_mutex_unlock(&data->philos[i].meal_lock);
        
        time_since_meal = current_time - last_meal;
        
        // 🔍 DEBUG: Imprimir cada 100ms
        static long long last_print = 0;
        if (current_time - last_print > 100)
        {
            printf("DEBUG: Philo %zu - Last meal: %lld ago (limit: %zu)\n", 
                   data->philos[i].id, time_since_meal, data->tt_die);
            last_print = current_time;
        }
        
        if (time_since_meal >= (long long)data->tt_die)
        {
            printf("💀 DEATH: Philo %zu - %lld >= %zu\n", 
                   data->philos[i].id, time_since_meal, data->tt_die);
            print_status(&data->philos[i], DIE);
            set_death(data);
            return (true);
        }
        
        i++;
    }
    
    return (false);
}

bool	check_meals(t_data *data)
{
	size_t	i;

	if (data->eat_count == -1)
		return (false);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (data->philos[i].meals < (size_t)data->eat_count)
		{
			pthread_mutex_unlock(&data->philos[i].meal_lock);
			return (false);
		}
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		i++;
	}
	set_death(data);
	return (true);
}
