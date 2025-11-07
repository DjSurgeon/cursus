/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:49:31 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/07 11:03:09 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create_struct.c
 * @brief Contains functions responsible for initializing the main simulation
 * data structure.
 * This file handles the allocation of the primary @ref t_philo structure,
 * argument validation via @ref check_arguments, and parsing the command-line
 * inputs into the structure fields.
 */
#include "philo.h"

/**
 * @brief Initializes the main simulation data structure (@ref t_philo).
 * This function performs three key steps:
 * 1. **Allocation:** Dynamically allocates memory for a single
 * @ref t_philo structure using @ref ft_calloc.
 * 2. **Validation:** Calls @ref check_arguments to ensure all command-line
 * parameters are valid (numeric, non-negative, etc.).
 * 3. **Parsing:** Converts the validated string arguments into the
 * corresponding `size_t` fields using @ref ft_atoi.
 * If any step fails (memory allocation or argument validation), the function
 * handles the error by returning NULL.
 * @param argv The array of command-line argument strings passed from main(),
 * where argv[1] is the first parameter.
 * @return t_philo* Pointer to the newly allocated and initialized
 * @ref t_philo structure, or **NULL** if allocation fails or arguments
 * are invalid.
 * @note **Memory Management:** The memory for `data_struct` is allocated here
 * using @ref ft_calloc. If successful, the **caller** is responsible
 * for **freeing** this pointer.
 * @note **Error Handling:** If `ft_calloc` fails, it returns NULL.
 * If `check_arguments` fails, it returns NULL, and no memory needs to be freed
 * locally, as `data_struct` was not fully initialized/used yet.
 * @warning It is assumed that `check_arguments` performs thorough validation
 * (including range and type checks) before `ft_atoi` is called.
 * If validation fails, the function returns prematurely.
 */
t_philo	*init_philo(char **argv)
{
	t_philo	*data_struct;

	data_struct = ft_calloc(1, sizeof(t_philo));
	if (!data_struct)
		return (NULL);
	if (!check_arguments(argv))
		return (free(data_struct), NULL);
	data_struct->n_philos = ft_atoi(argv[1]);
	data_struct->tt_die = ft_atoi(argv[2]);
	data_struct->tt_eat = ft_atoi(argv[3]);
	data_struct->tt_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data_struct->eat_count = ft_atoi(argv[5]);
	else
		data_struct->eat_count = 0;
	return (data_struct);
}
