/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:04:37 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/03 20:13:44 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}						t_stack_node;

// Estructura para los stack

// Modulo de operaciones del stack

// Modulo de parseo y validaciones de entrada

char	**argument_to_array(char **argv);
bool	check_array(char **c_array);
int		*char_array_to_int_array(char **argv);

// Modulo de manipulacion del stack

// Modulo de algoritmos

#endif
