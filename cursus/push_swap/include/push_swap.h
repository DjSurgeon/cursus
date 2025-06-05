/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:04:37 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/05 13:27:32 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// Modulo de parseo y validaciones de entrada

char	**argument_to_array(char *argv);
bool	check_array(char **c_array);
int		*char_array_to_int_array(char **argv, int length);

// Estructura para los stack

t_stack	*create_stack(char **array);

// Modulo de operaciones del stack

// Modulo de manipulacion del stack

// Modulo de algoritmos

// Liberaciones de memoria

void	free_array(char **c_array);
void	free_stack(t_stack **stack);
#endif
