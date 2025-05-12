/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:24:39 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/12 14:25:13 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercises.h"

int	main(int argc, char *argv[])
{
	t_node *stack_a;
	t_node *stack_b;
	t_node	*create_stack;
	int	i;

	i = 1;
	stack_a = NULL;
	stack_b =  NULL;
	if (argc >= 2)
	{
		while (i < argc)
		{
			if (!check_arguments(argc, &argv[i]))
				return (printf("Error argumentos no validos"));
			i++;
		}
		printf("argumentos validos!\n");
		printf("añadiendo argumentos al stack...\n");
		i = 1;
		while (i < argc)
		{
			create_stack = create_node(atoi(argv[i]));
			add_back(&stack_a, create_stack);
			i++;
		}
		printf("mostrando argumentos en el stack:\n");
		print_list(stack_a);
	}
	else
	{
		printf("no hay argumentos, devolviendo el control al usuario");
		return (0);
	}
	return (0);
}
