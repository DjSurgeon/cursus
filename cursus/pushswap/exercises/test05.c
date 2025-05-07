/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:21:34 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/07 15:14:22 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercises.h"

int	main(void)
{
	int		values[10] = {42,13,28,34,46,58,69,70,85,99};
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < 10)
	{
		t_node	*new_node_a;
		t_node	*new_node_b;
		new_node_a = create_node(values[i]);
		new_node_b = create_node(values[i]);
		add_back(&stack_a, new_node_a);
		add_front(&stack_b, new_node_b);
		i++;
	}
	printf("Stack A\n");
	print_list(stack_a);
	printf("Stack B\n");
	print_list(stack_b);
	printf("Length: %d\n", list_length(stack_a));
	printf("Length: %d\n", list_length(stack_b));
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
