/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:49:31 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/07 13:07:22 by sergio-jime      ###   ########.fr       */
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

static	t_data *init_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals = 0;
		data->philos[i].last_meal = 0;
		i++;
	}
	return (data);
}

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
t_data	*init_data(char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	if (!check_arguments(argv))
		return (free(data), NULL);
	data->n_philos = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->eat_count = ft_atoi(argv[5]);
	else
		data->eat_count = 0;
	data->philos = ft_calloc(data->n_philos, sizeof(t_philo));
	if (!data->philos)
		return (free(data), NULL);
	data = init_philos(data);
	if (!data)
		return (free(data->philos), free(data), NULL);
	return (data);
}
