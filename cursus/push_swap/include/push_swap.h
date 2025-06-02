/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:04:37 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/02 13:40:50 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}						t_stack_node;

// Estructura para los stack

// Modulo de operaciones del stack

// Modulo de parseo y validaciones de entrada

bool	check_arguments(int argc, char **argv);

// Modulo de manipulacion del stack

// Modulo de algoritmos

#endif
