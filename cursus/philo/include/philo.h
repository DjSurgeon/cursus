/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:09:47 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/07 13:27:39 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo.h
 * @brief Main header file for the Philosophers simulation project.
 * This file contains all necessary standard library includes, project-specific
 * constants, the definition of key data structures (structs), and the
 * function prototypes required across the entire project.
 * It acts as the central hub for defining the simulation's data model and
 * available utilities.
 */

#ifndef PHILO_H
# define PHILO_H

/* ************************************************************************** */
/* Standard Library Includes ************************************************ */
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

/* ************************************************************************** */
/* Structs ****************************************************************** */

typedef struct s_philo
{
	size_t	id;
	size_t	meals;
	long	last_meal;
}				t_philo;

/**
 * @struct s_philo
 * @brief Main data structure holding simulation parameters.
 * This structure stores the initial configuration read from the command-line
 * arguments, setting the stage for the simulation environment.
 * @var t_philo::n_philos
 * The total number of philosophers (and forks) in the simulation.
 * @var t_philo::tt_die
 * Time (in milliseconds) a philosopher can go without eating before dying.
 * @var t_philo::tt_eat
 * Time (in milliseconds) a philosopher spends eating.
 * @var t_philo::tt_sleep
 * Time (in milliseconds) a philosopher spends sleeping.
 * @var t_philo::eat_count
 * Optional argument: The minimum number of times each philosopher must eat.
 * Set to 0 or a sentinel value if the argument is not provided.
 * @note This structure will likely need expansion later to include dynamic
 * elements like mutexes, threads, and the array of individual philosopher
 * structs.
 */
typedef struct s_data
{
	size_t	n_philos;
	size_t	tt_die;
	size_t	tt_eat;
	size_t	tt_sleep;
	size_t	eat_count;
	t_philo	*philos;
}				t_data;

/* ************************************************************************** */
/* Utils ******************************************************************** */

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);

/* ************************************************************************** */
/* Parser ******************************************************************* */
/**
 * @brief Validates all command-line arguments for correctness.
 * Checks if arguments are numeric, within limits, and non-negative.
 * @param arr Array of argument strings (starting from argv[1]).
 * @return bool Returns true if all arguments are valid, false otherwise.
 */

bool	check_arguments(char **arr);

/* ************************************************************************** */
/* Init ********************************************************************* */
/**
 * @brief Initializes the main simulation data structure.
 * Parses and validates arguments, allocates the main @ref t_philo structure,
 * and fills its fields with the validated parameters.
 * @param argv The array of argument strings from main().
 * @return t_philo* Pointer to the newly allocated and initialized structure,
 * or NULL if memory allocation fails or arguments are invalid.
 * @note The returned pointer must be freed by the caller (i.e., main()).
 */

t_data	*init_data(char **argv);
t_data	*fill_data(char **argv, t_data *data);
t_data	*fill_philos(t_data *data);

/* ************************************************************************** */
/* Tests ******************************************************************** */

void	print_struct(t_data *data);

#endif
