/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:04:37 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/16 01:21:01 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
# include <limits.h>
# include <math.h> // esta no se puede usar hay que hacer una nueva

typedef struct s_stack
{
	int				value;
	int				index;
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

bool	check_sort(t_stack **stack, t_stack **stack_b);
int		stack_size(t_stack **stack);
bool	is_sort(t_stack **stack);
int		max_stack_index(t_stack **stack);
void	k_sort(t_stack **stack, t_stack **stack_b, int size);
size_t	min_stack_value(t_stack **stack);
void	add_correct_index(t_stack **stack, int size);
int		rb_count(t_stack **stack, int index);

// Liberaciones de memoria

void	free_array_c(char **c_array);
void	free_array_i(int **i_array);
void	free_stack(t_stack **stack);

// Utils

void	ft_ps_printlist(t_stack *head);
#endif
