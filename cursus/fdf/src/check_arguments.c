/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:55:52 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/02 18:14:16 by sergio-jime      ###   ########.fr       */
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
static bool	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (false);
	if (ft_strnstr(path + (len - 4), ".fdf", 4) == NULL)
		return (print_error("Error Invalid Extension\n"), false);
	return (true);
}

/**
 * create path
 */
static char	*create_path(char *str)
{
	char	*path;
	char	*finalpath;

	path = "../fdf/maps/";
	finalpath = ft_strjoin(path, str);
	if (!finalpath)
		return (print_error("Error Memory Allocation\n"), NULL);
	return (finalpath);
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
	char	*finalpath;

	finalpath = create_path(str);
	if (finalpath == NULL)
		return (false);
	fd = open_path(finalpath);
	if (fd == -1)
		return (free(finalpath), false);
	else if (!check_extension(finalpath))
		return (close(fd), free(finalpath), false);
	else if (!validate_map(finalpath, fd))
		return (close(fd), free(finalpath), false);
	return (close(fd), free(finalpath), true);
}
