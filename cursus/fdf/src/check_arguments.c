/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:55:52 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/01 19:35:27 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Validates file extension and processes map content line
 * by line.
 * Checks if the file has correct .fdf extension. If valid,
 * reads the file line by line, processing each line through check_coordinate()
 * Upon reaching end of file, outputs map dimensions and exits.
 * @param finalpath Full path to the map file being validated.
 * @param fd File descriptor of the opened map file.
 * @return void Exits program with EXIT_FAILURE on invalid extension,
 * or EXIT_SUCCESS after processing entire file.
 */
static bool	check_extension(char *finalpath, int fd)
{
	if (ft_strnstr(finalpath, ".fdf", ft_strlen(finalpath)) == NULL)
	{
		close (fd);
		return (print_error("Error unknown extension", finalpath), false);
	}
	return (true);
}

/**
 * @brief Main map validation function: handles path construction and
 * file access.
 * Construct the full path to the map file, attempts to open it, and initiates
 * the validation process throught check_extension(). 
 * Handles file access errors.
 * @param str Map filename (without path).
 * @return void Exits program with EXIT_FAILURE on file access errors,
 * or continues validation through check_extension.
 */
bool	check_map(char *str)
{
	int		fd;
	char	*path;
	char	*finalpath;

	path = "../fdf/maps/";
	finalpath = ft_strjoin(path, str);
	fd = open(finalpath, O_RDONLY);
	if (fd < 0)
		return (print_error("Error open()", finalpath), false);
	else
	{
		if (!check_extension(finalpath, fd))
			return (print_error("Error extension", finalpath), false);
		else if (!check_file(finalpath, fd))
			return (print_error("Error file", finalpath), false);
	}
	return (close(fd), true);
}
