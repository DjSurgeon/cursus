/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:59:01 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/07 13:31:17 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_struct(t_data *data)
{
	size_t	i;

	i = 0;
	if (!data)
		printf("ERROR: Estructura Vacia\n");
	printf("Datos de Entrada del Programa========\n");
	printf("Number of philosophers: [%ld]\n", data->n_philos);
	printf("Time to die: [%ld]\n", data->tt_die);
	printf("Time to eat: [%ld]\n", data->tt_eat);
	printf("Time to sleep: [%ld]\n", data->tt_sleep);
	if (data->eat_count)
		printf("Times must eat: [%ld]\n", data->eat_count);
	printf("Datos de Entrada de los Filosofos========\n");
	while (i < data->n_philos)
	{
		printf("Memory: [%p] - Philo ID:[%ld] - Meals [%ld] - LastMeal [%ld]\n", (void *)&data->philos[i], data->philos[i].id, data->philos[i].meals, data->philos[i].last_meal);
		i++;
	}
}
