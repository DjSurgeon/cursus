/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:36:42 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/03/22 02:35:20 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// funcion para verificar argumentos separados
bool	ft_isnumber(char *str)
{
	size_t	i;

	i = 0;
	if(str[i] == '+' || str[i] == '-')
	i++;
	// ./push_swap 1 +2 ++3 --3 - + - Error
	if(str[i] == '+' || str[i] == '-' || str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		// ./push_swap 1 +2 -3 two - Error
		if(ft_isdigit(!str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_arguments(int argc, char *argv[])
{
	size_t	i;
	// ./push_swap "" - Error
	if (argc == 2 && argv[1][0] == '\0')
		return (false);
	// ./push_swap "      " - Error
	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			ft_isspace(argc[1][i])
			i++;
		}
		return (false):
	}
	return (true);
}

bool	check_arguments(int argc, char *argv[])
{
	if (argc < 2)
	{
		
	}
}
int main(int argc, char *argv[])
{
	if(!check_arguments(argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
