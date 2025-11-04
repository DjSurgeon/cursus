/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:50:12 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/04 14:15:36 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_arguments(char **arr)
{
	size_t	i;
	size_t	j;
	int		number;

	i = 1;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
				return (printf("ERROR: Only digits\n"), false);
			j++;
		}
		if (ft_atoi(arr[2]) < ft_atoi(arr[3]))
			return (printf("ERROR: To shoort times\n"), false);
		number = ft_atoi(arr[i]);
		if (number <= 0)
			return (printf("ERROR: Only positive times\n"), false);
		else if (i == 1 && number == 1)
			return (printf("ERROR: Only one philosopher\n"), false);
		else if (i == 1 && number == 2)
			return (printf("ERROR: Especial case 2 philosophers\n"), false);
		i++;
	}
	return (true);
}
