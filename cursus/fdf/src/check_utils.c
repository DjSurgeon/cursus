/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:16:29 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 17:54:50 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * open file
 */
int	open_path(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (print_error("Error Invalid File Descriptor\n"), -1);
	return (fd);
}

/**
 * check is a hexadecimal number
 */
bool	is_valid_hexa(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0')
		i++;
	if (str[i] == 'x')
		i++;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isxdigit(str[i]) == 0)
			return (ft_printf("Invalid hexadecimal"), free(str), false);
		i++;
	}
	return (true);
}

/**
 * check digits
 */
bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (str[i] == '\0')
		return (ft_printf("Fallo1"), free(str), false);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0)
			return (ft_printf("Invalid character"), free(str), false);
		i++;
	}
	return (true);
}

/**
 * check width
 */
bool	is_correct_width(t_sizemap *map)
{
	if (map->expected_width != 0 && map->expected_width != map->width)
	{
		ft_printf("Error different width map");
		return (false);
	}
	return (true);
}
