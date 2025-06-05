/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:34:04 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/05 13:35:14 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ps_printlist(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}
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
	//t_stack	*stack_b;
	char		**arr;

	//stack_b = NULL;
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
			ft_ps_printlist(stack_a);
			free_stack(&stack_a);
		}
		free_array(arr);
	}
	else
	{
		if (check_array(argv + 1))
		{
			stack_a = create_stack(argv + 1);
			ft_ps_printlist(stack_a);
			free_stack(&stack_a);
		}
	}
	return (EXIT_SUCCESS);
}
