/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:08:26 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/16 01:24:21 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Main entry point for the Philsophers project.
 * This file contains the primary execution flow for the dining philosophers
 * simulation. It handles argument validation, initializes the core data
 * structure using @ref init_data, runs the simulation, and ensures all
 * allocated memory is properly freed.
 */
#include "philo.h"

/**
 * @brief Main function of the Philosophers simulation.
 * This function orchestrates the entire simulation lifecycle:
 * 1. **Argument Check:** Validates the number of command-line arguments
 * (must be 4 or 5).
 * 2. **Initialization:** Calls @ref init_data to allocate memory, parse
 * arguments, and initialize all mutexes and structures.
 * 3. **Execution:** Calls @ref start_dinner to create threads and run
 * the simulation.
 * 4. **Cleanup:** Calls @ref final_clean to destroy mutexes and free
 * all memory.
 * The expected arguments are:
 * 1. number_of_philosophers (N)
 * 2. time_to_die (T_die)
 * 3. time_to_eat (T_eat)
 * 4. time_to_sleep (T_sleep)
 * 5. [number_of_times_each_philosopher_must_eat] (Optional)
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 * @return int Returns 0 on successful execution and cleanup.
 * Returns 1 on error.
 * @code
 * ./philo 5 800 200 200
 * 		// 5 philosophers, time to die: 800ms, eat: 200ms, sleep: 200ms
 * ./philo 5 800 200 200 7
 * 		// Same as above, but each philosopher must eat at least 7 times
 * @endcode
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc == 5 || argc == 6)
	{
		data = init_data(argv);
		if (!data)
			return (1);
		if (!start_dinner(data))
		{
			final_clean(data);
			return (1);
		}
		final_clean(data);
	}
	else
	{
		printf("Usage: ./philo <n_philos> <tt_die> <tt_eat> ");
		printf("<tt_sleep> [must_eat_count]\n");
		return (1);
	}
	return (0);
}
