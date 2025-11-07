/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:08:26 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/07 10:36:17 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Main entry point for the Philsophers project.
 * This file contains the primary execution flow for the dining philosophers
 * simulation. It handles argument validation, initializes the core data
 * structure using @ref init_philo, runs the simulation, and ensures all
 * allocated memory is properly freed.
 */
#include "philo.h"

/**
 * @brief Main function of the Philosophers simulation.
 * It validates the number of command-line arguments (must be 4 or 5
 * parameters), initializes the main simulation structure @ref t_philo,
 * and executes the simulation. If initialization fails, it handles the error.
 * Finally, it ensures the cleanup of the allocated resources.
 * The expected arguments are:
 * 1. number_of_philosophers (N)
 * 2. time_to_die (T_die)
 * 3. time_to_eat (T_eat)
 * 4. time_to_sleep (T_sleep)
 * 5. [number_of_times_each_philosopher_must_eat] (Optional)
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 * @return int Returns 0 on successful execution and cleanup.
 * Returns -1 if the simulation initialization fails (@ref init_philo).
 * @note This function is responsible for calling @ref init_philo to allocate
 * the main data structure and then **freeing** that structure
 * using `free(data_philo)` before exiting.
 * @warning The function relies on subsequent modules (like `print_struct`)
 * and the simulation logic (not visible here) to complete successfully.
 * @code
 * ./philo 5 800 200 200
 * 		// 5 philosophers, time to die: 800ms, eat: 200ms, sleep: 200ms
 * ./philo 5 800 200 200 7
 * 		// Same as above, but each philosopher must eat at least 7 times
 * @endcode
 */
int	main(int argc, char **argv)
{
	t_philo	*data_philo;

	data_philo = NULL;
	if (argc == 5 || argc == 6)
	{
		data_philo = init_philo(argv);
		if (!data_philo)
			return (-1);
		print_struct(data_philo);
	}
	else
	{
		printf("Usage: ./philo <n_philos> <tt_die> <tt_eat> ");
		printf("<tt_sleep> [must_eat_count]\n");
	}
	free(data_philo);
	return (0);
}
