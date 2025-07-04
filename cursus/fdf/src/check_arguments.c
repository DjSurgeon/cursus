/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:55:52 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/04 15:05:49 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Validates file extension for FDF map files.
 * Checks if the provided file path has the correct ".fdf" extension.
 * The extension must be exactly 4 characters long at the end of the path.
 * @param path Full path to the map file being validated.
 * @return true If the extension is valid.
 * @return false If the extension is invalid (with error message printed).
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
 * @brief Construct the full path to the map file.
 * Combines the base directory path (../fdf/maps/) with the provided filename
 * to create the full path to the map file.
 * @param str Map filename (without path).
 * @return char* Full path to the map file, or NULL if memory allocation
 * fail (with error message).
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
 * @brief Main map validation function: coordinates file access
 * and validation.
 * Construct the full path to the map file, open it, and performs
 * sequential validation checks (file existence, extension and content).
 * Manage resources (file descriptor and memory) throughout the process.
 * @param str Map filename (without path).
 * @return true If all validations pass (file exits, valid extension,
 * and proper content).
 * @return false If any validation fails (with appropiate error 
 * messages printed).
 */
t_sizemap	*check_map(char *str, t_sizemap *map)
{
	int		fd;
	char	*finalpath;

	finalpath = create_path(str);
	if (finalpath == NULL)
		return (NULL);
	fd = open_path(finalpath);
	if (fd == -1)
		return (free(map), free(finalpath), NULL);
	else if (!check_extension(finalpath))
		return (free(map), close(fd), free(finalpath), NULL);
	map = validate_map(finalpath, fd, map);
	if (map == NULL)
		return (free(map), close(fd), free(finalpath), NULL);
	return (close(fd), free(finalpath), map);
}
