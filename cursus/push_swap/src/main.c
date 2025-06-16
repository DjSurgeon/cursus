/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:34:04 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/16 17:30:54 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Auxiliary function for main when argc = 2.
 * Handles the case where arguments are passed as a single quoted
 * string of numbers.
 * @param argv Array of argument strings, where argv[1] is the quoted string
 * containing space-separated numbers.
 * @return int EXIT_SUCCESS on success, or EXIT_FAILURE if memory allocation or
 * validation fails.
 */
static int	main_aux1(char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arr;

	stack_a = NULL;
	stack_b = NULL;
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
	return (EXIT_SUCCESS);
}

/**
 * @brief Auxiliary function for main when argc > 2.
 * Handles the case where arguments are passed as multiple
 * individual numeric strings.
 * @param argv Array of arguments strings, where argv[1] to argv[argc - 1]
 * represent the numbers.
 * @return int EXIT_SUCCESS on success.
 */
static int	main_aux2(char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (check_array(argv + 1))
	{
		stack_a = create_stack(argv + 1);
		check_sort(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Entry point for push_swap: parse command-line arguments into a
 * string array.
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
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
		main_aux1(argv);
	else
		main_aux2(argv);
	return (EXIT_SUCCESS);
}
