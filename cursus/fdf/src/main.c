/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:34:42 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/28 18:45:01 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file main.c
 * @brief Entry point for the FDF program.
 * Validates input arguments, processes the map file, initializes the FDF
 * application, and manage memory cleanup.
 * The program requires exactly one argument representing the map
 * file path.
 * @param argc Number or command line argument.
 * @param argv Array of arguments strings where argv[1] is the map file path.
 * @return int EXIT_SUCCESS on successful validation, EXIT_FAILURE
 * on any error.
 * @note Usage: ./fdf <map_file.fdf>
 */

int	main(int argc, char *argv[])
{
	t_sizemap	*fdf;

	if (argc != 2)
	{
		print_error("Invalid arguments\nUsage: ./fdf <map_file.fdf>");
		exit(EXIT_FAILURE);
	}
	else
	{
		fdf = NULL;
		fdf = create_sizemap(fdf);
		fdf = check_map(argv[1], fdf);
		if (fdf == NULL)
			exit(EXIT_FAILURE);
		init_fdf(fdf);
	}
	free_map(fdf, fdf->height);
	return (EXIT_SUCCESS);
}
