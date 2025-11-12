/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:09:47 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/12 11:29:13 by sergio-jime      ###   ########.fr       */
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

typedef pthread_mutex_t t_mutex;

/* ************************************************************************** */
/* Structs ****************************************************************** */

/**
 * @brief Structure holding the dynamic state for a single philosopher.
 * This structure will eventually be used to manage each philosopher's thread
 * and their specific state variables during the simulation.
 * @var t_philo::id
 * The unique identification number of the philosopher (1 to N).
 * @var t_philo::meals
 * The count of how many times this philosopher has eaten.
 * @var t_philo::last_meal
 * The timestamp (in milliseconds) of when the philosopher last started eating.
 * @var t_philo::start_t
 * The starting timestamp (in milliseconds) of the entire simulation.
 * @note This structure is designed to be part of an array within the main 
 * @ref t_data structure.
 * @note It will need expansion later to include the thread ID, pointers to 
 * forks (mutexes), and a pointer back to the main @ref t_data.
 */
typedef struct s_philo
{
	size_t			id;
	size_t			meals;
	long long		last_meal;
	pthread_t		thread;
	t_mutex			*l_forks;
	t_mutex			*r_forks;
	struct s_data	*data;
}					t_philo;

/**
 * @brief Main data structure holding global simulation parameters and
 * philosopher data.
 * This structure stores the configuration read from the command-line
 * arguments, the array of philosophers, and will hold shared resources
 * like global mutexes or flags.
 * @var t_data::n_philos
 * The total number of philosophers (and forks) in the simulation.
 * @var t_data::tt_die
 * Time (in milliseconds) a philosopher can go without eating before dying.
 * @var t_data::tt_eat
 * Time (in milliseconds) a philosopher spends eating.
 * @var t_data::tt_sleep
 * Time (in milliseconds) a philosopher spends sleeping.
 * @var t_data::eat_count
 * Optional argument: The minimum number of times each philosopher must eat.
 * 0 if not specified.
 * @var t_data::philos
 * Pointer to an array of @ref t_philo structures, one for each philosopher.
 * @note This structure centralizes access to global state and parameters.
 */
typedef struct s_data
{
	size_t			n_philos;
	size_t			tt_die;
	size_t			tt_eat;
	size_t			tt_sleep;
	size_t			eat_count;
	t_mutex			*forks;
	t_mutex			write_lock;
	t_mutex			death_lock;
	t_mutex			meal_lock;
	t_philo			*philos;
	bool			philo_died;
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
bool		fill_philos(t_data *data);
bool		fill_forks(t_data *data);

/* ************************************************************************** */
/* Time ********************************************************************* */

long long	get_time(void);
void		ft_usleep(long long ms);
long long	get_timestamp(long long start);

/* ************************************************************************** */
/* Mutex ******************************************************************** */

void		clean_mutex(t_data *data);

#endif
