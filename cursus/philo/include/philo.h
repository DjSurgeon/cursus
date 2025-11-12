/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:09:47 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/13 00:18:24 by sergio-jime      ###   ########.fr       */
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
# include <sys/time.h>
# include <pthread.h>

/* ************************************************************************** */
/* Alias * ****************************************************************** */

/**
 * @brief Alias for pthread_mutex_t for cleaner code readability.
 */
typedef pthread_mutex_t	t_mutex;

/* ************************************************************************** */
/* Structs ****************************************************************** */

/**
 * @brief Structure holding the dynamic state for a single philosopher.
 * This structure will eventually be used to manage each philosopher's thread
 * and their specific state variables during the simulation.
 * @var t_philo::id
 * The unique identification number of the philosopher (1 to n_philos).
 * @var t_philo::meals
 * The count of how many times this philosopher has eaten.
 * @var t_philo::last_meal
 * The timestamp (in milliseconds) of when the philosopher last started eating.
 * Used to check for starvation.
 * @var t_philo::thread
 * The pthread_t handle for this philosopher's execution thread.
 * @var t_philo::l_fork
 * Pointer to the mutex representing the fork to the philosopher's left.
 * @var t_philo::r_fork
 * Pointer to the mutex representing the fork to the philosopher's right.
 * @var t_philo::data
 * Pointer back to the main simulation data structure for accessing
 * global state.
 */
typedef struct s_philo
{
	size_t			id;
	size_t			meals;
	long long		last_meal;
	pthread_t		thread;
	t_mutex			*l_fork;
	t_mutex			*r_fork;
	struct s_data	*data;
}					t_philo;

/**
 * @brief Main data structure holding global simulation parameters and
 * philosopher data.
 * This structure stores the configuration read from the command-line
 * arguments, the array of philosophers and fork (mutexes), and coordinates
 * global state like the death flag and timig.
 * @var t_data::n_philos
 * The total number of philosophers (and forks) in the simulation.
 * @var t_data::tt_die
 * Time (in milliseconds) a philosopher can go without eating before dying.
 * @var t_data::tt_eat
 * Time (in milliseconds) a philosopher spends eating (holds both forks).
 * @var t_data::tt_sleep
 * Time (in milliseconds) a philosopher spends sleeping.
 * @var t_data::eat_count
 * Optional argument: The minimum number of times each philosopher must eat.
 * @var t_data::forks
 * Array of mutexes representing the forks on the table.
 * @var t_data::write_lock
 * Mutex for synchronizing log output to prevent interleaved messages.
 * @var t_data::death_lock
 * Mutex for protecting access to the philo_died flag.
 * @var t_data::meal_lock
 * Mutex for protecting access to meal-related data (last_meal, meals).
 * @var t_data::philos
 * Array of philosopher structures, one for each philosopher.
 * @var t_data::philo_died
 * Flag indicating whether any philosopher has died, terminating the simulation.
 * @var t_data::start_t
 * The starting timestamp (in milliseconds) of the entire simulation.
 */
typedef struct s_data
{
	size_t			n_philos;
	size_t			tt_die;
	size_t			tt_eat;
	size_t			tt_sleep;
	int				eat_count;
	t_mutex			*forks;
	t_mutex			write_lock;
	t_mutex			death_lock;
	t_mutex			meal_lock;
	t_philo			*philos;
	pthread_t		monitor;
	int				philo_died;
	long long		start_t;
}					t_data;

/* ************************************************************************** */
/* Utils ******************************************************************** */

void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);

/* ************************************************************************** */
/* Parser ******************************************************************* */

bool		check_arguments(char **arr);

/* ************************************************************************** */
/* Init ********************************************************************* */

t_data		*init_data(char **argv);
t_data		*fill_data(char **argv, t_data *data);
bool		fill_philos(t_data *data, t_philo *philos);
bool		fill_forks(t_data *data, t_mutex *forks);

/* ************************************************************************** */
/* Time ********************************************************************* */

long long	get_time(void);
void		ft_usleep(long long ms);
long long	get_timestamp(long long start);

/* ************************************************************************** */
/* Clean ******************************************************************** */

void		clean_mutex_data(t_data *data);
void		clean_mutex_forks(t_mutex *forks, size_t initialized);
void		final_clean(t_data *data);

/* ************************************************************************** */
/* Simulation *************************************************************** */

bool		start_dinner(t_data *data);

#endif
