/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:34:04 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/03 23:48:56 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	//t_stack_node	*stack_a;
	//t_stack_node	*stack_b;
	char		**arr;

	//stack_a = NULL;
	//stack_b = NULL;
	(void) argv;
	if (argc < 2)
		ft_printf("No hay argumentos, devolviendo el control al usuario.\n");
	if (argc == 2)
	{
		arr = argument_to_array(argv);
		check_array(arr);
	}
	int	i = 0;
	while (arr[i] != NULL)
	{
		ft_printf("main -> %s\n", arr[i]);
		free (arr[i]);
		i++;
	}
	free (arr);
	return (0);
}
