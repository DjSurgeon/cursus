/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:59:01 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/09/17 12:29:13 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_struct(t_philo *data_struct)
{
	if (!data_struct)
		printf("ERROR: Estructura Vacia\n");
	printf("Number of philosophers: [%ld]\n", data_struct->n_philos);
	printf("Time to die: [%ld]\n", data_struct->tt_die);
	printf("Time to eat: [%ld]\n", data_struct->tt_eat);
	printf("Time to sleep: [%ld]\n", data_struct->tt_sleep);
	if (data_struct->eat_count)
		printf("Time must eat: [%ld]\n", data_struct->eat_count);
}
