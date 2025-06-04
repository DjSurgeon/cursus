/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:34:04 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/04 13:13:43 by sergio-jime      ###   ########.fr       */
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
	//t_stack_node	*stack_a;
	//t_stack_node	*stack_b;
	char		**arr;

	//stack_a = NULL;
	//stack_b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
	{
		arr = argument_to_array(argv[1]);
		if (arr == NULL)
			return (EXIT_FAILURE);
		check_array(arr);
		free_array(arr);
	}
	else
	{
		check_array(argv + 1);
	}
	return (EXIT_SUCCESS);
}
