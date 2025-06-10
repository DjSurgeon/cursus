/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:34:04 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/10 10:50:40 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ps_printlist(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		ft_printf("NULL List");
	temp = head;
	while (temp != NULL)
	{
		ft_printf("[%d]", temp->value);
		ft_printf("[%p]", temp->next);
		temp = temp->next;
		if (temp != NULL)
			ft_printf(" -> ");;
	}
	ft_printf("\n");
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

	stack_a = NULL;
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
			//max_value_stack(&stack_a);
			//ps_push_b(&stack_a, &stack_b, true);
			check_sort(&stack_a);
			ft_ps_printlist(stack_a);
		}
	}
	return (EXIT_SUCCESS);
}
