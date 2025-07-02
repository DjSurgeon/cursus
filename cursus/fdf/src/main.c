/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:34:42 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 21:17:48 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Entry point for the FDF program: validates input and processes
 * map file.
 * The program requires exactly one argument representing the map
 * file path.
 * Validates the input arguments and initiates map validation.
 * Usage: ./fdf map_file.fdf
 * @param argc Number or command line argument.
 * @param argv Array of arguments strings where argv[1] is the map file path.
 * @return int EXIT_SUCCESS on successful validation, EXIT_FAILURE
 * on any error.
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
