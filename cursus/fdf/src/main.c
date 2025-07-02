/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:34:42 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 16:45:58 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Entry point for the FDF program: validates input and processes
 * map file.
 * The program requires exactly one argument representing the map
 * file path.
 * Usage: ./fdf map_file.fdf
 * @param argc Number or command line argument.
 * @param argv Array of arguments strings where argv[1] is the map file path
 * @return int Always returns EXIT_SUCESS
 */

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Invalid arguments\nUsage: ./fdf <map_file.fdf>");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (!check_map(argv[1]))
			exit(EXIT_FAILURE);
	}
	ft_printf("SUCCESS");
	return (EXIT_SUCCESS);
}
