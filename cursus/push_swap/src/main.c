/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:34:04 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/16 01:21:25 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Entry point for push_swap: parse command-line arguments into a string
 * array.
 * The program accepts a single quoted string of numbers
 * ./push_swap "3 6 8 -9"
 * or multiple individual numeric arguments
 * ./push_swap -34 3 4 09
 * @param argc Number or command-line arguments.
 * @param argv Array of argument strings.
 * @return int EXIT_SUCCESS on success, or EXIT_FAILURE if allocation or
 * validation fails.
 */

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char		**arr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
	{
		arr = argument_to_array(argv[1]);
		if (arr == NULL)
			return (EXIT_FAILURE);
		if (check_array(arr))
		{
			stack_a = create_stack(arr);
			check_sort(&stack_a, &stack_b);
			free_stack(&stack_a);
			free_stack(&stack_b);
		}
		free_array_c(arr);
	}
	else
	{
		if (check_array(argv + 1))
		{
			stack_a = create_stack(argv + 1);
			check_sort(&stack_a, &stack_b);
			free_stack(&stack_a);
			free_stack(&stack_b);
		}
	}
	return (EXIT_SUCCESS);
}
