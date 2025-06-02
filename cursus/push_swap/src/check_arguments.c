/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:25:03 by serjimen          #+#    #+#             */
/*   Updated: 2025/06/02 13:40:10 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_arguments(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[argc][i] != '\0')
	{
		if (ft_isdigit(argv[argc][i]) == 1)
		{
			i++;
		}
		else
		{
			return (false);
		}
	}
	return (true);
}
