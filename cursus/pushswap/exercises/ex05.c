/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:57:53 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/12 14:35:06 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercises.h"

bool ft_signednbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (isspace(str[i]))
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

bool check_arguments(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!isdigit(argv[i][0]))
			return (false);
		if (!ft_signednbr(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
