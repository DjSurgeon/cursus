/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:04:37 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/17 12:43:32 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.h
 * @brief Main header for Push Swap project containing all structures and
 * function declarations.
 */
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
	int				index;
	struct s_stack	*next;
}					t_stack;

/* ----------------------- Parsing and Validation Module -------------------- */

char	**argument_to_array(char *argv);
bool	check_array(char **c_array);
int		*char_array_to_int_array(char **argv, int length);

/* --------------------------- Stack Operations ----------------------------- */

t_stack	*create_stack(char **array);
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

/* ------------------------- Sorting Algorithms ----------------------------- */

bool	check_sort(t_stack **stack, t_stack **stack_b);
int		stack_size(t_stack **stack);
bool	is_sort(t_stack **stack);
int		max_stack_index(t_stack **stack);
void	k_sort(t_stack **stack, t_stack **stack_b, int size);
int		min_stack_value(t_stack **stack);
void	add_correct_index(t_stack **stack, int size);
int		rb_count(t_stack **stack, int index);

/* ------------------------ Memory Management ------------------------------- */

void	free_array_c(char **c_array);
void	free_stack(t_stack **stack);

/* ---------------------------- Utilities ----------------------------------- */

void	ft_ps_printlist(t_stack *head);
#endif
