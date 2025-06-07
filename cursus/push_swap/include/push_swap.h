/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:04:37 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/07 18:18:09 by sergio-jime      ###   ########.fr       */
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

void	ps_swap_a(t_stack **stack, bool print);
void	ps_swap_b(t_stack **stack, bool print);
void	ps_swap_ss(t_stack **stack_a, t_stack **stack_b);
void	ps_push_b(t_stack **stack_a, t_stack **stack_b, bool print);
void	ps_push_a(t_stack **stack_a, t_stack **stack_b, bool print);
void	ps_rotate_a(t_stack **stack, bool print);
void	ps_rotate_b(t_stack **stack, bool print);
void	ps_rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	ps_reverse_a(t_stack **stack, bool print);
void	ps_reverse_b(t_stack **stack, bool print);
void	ps_reverse_rr(t_stack **stack_a, t_stack **stack_b);

// Modulo de algoritmos

bool	check_sort(t_stack **stack);
int		stack_size(t_stack **stack);
bool	is_sort(t_stack **stack);

// Liberaciones de memoria

void	free_array(char **c_array);
void	free_stack(t_stack **stack);
#endif
