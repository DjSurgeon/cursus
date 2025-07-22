/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:55:52 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/22 09:39:33 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file check_arguments.c
 * @brief Validates file extension for FDF map files.
 * Performs strict validation of the file extension to ensure it:
 * - Appears exactly at the end of the path.
 * - Matches the exact case-sensitive string ".fdf".
 * - Has exactly 4 characters in length.
 * @note The check is case-sensitive (.FDF will fail).
 * @note Requires the extension to be exactly at the end of the path.
 * @note Minimum path length requirement: 4 characters.
 * @param path Full filesystem path to the map file being validated.
 * Must be a null-terminated string.
 * @return true If the path has a valid .fdf extension.
 * @return false Otherwise (with error message printed to stderr).
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
 * @file check_arguments.c
 * @brief Construct the full path to the map file.
 * Combines the base direcctory path for map files with the provided filename
 * to create a complete filesystem path. The function uses the project's
 * standard map directory location (../fdf/maps).
 * @note The returned string is dynamically allocated and must be freed.
 * @param str Map filename (without path).
 * @return char* On success: Newly allocated string containing full path.
 * On failure: NULL (with error message printed to stderr).
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
 * @file check_arguments.c
 * @brief Main map validation function.
 * Performs comprenhensive validation of a map file including path
 * construction, file access check, extension validation, and content
 * verification. Manages all resources (file descriptor and memory)
 * thoughout the validation process.
 * @note This function performs the following validation steps:
 * 1 - Construct full path to map file.
 * 2 - Verifies file accessibility.
 * 3 - Validates file extesion (*.fdf).
 * 4 - Performs content validation and parsing.
 * @note Manage all resources (close file descriptors, frees memory)
 * even in error cases.
 * @param str Map filename or relative path.
 * @param map Pointer to existing t_sizemap structure or NULL.
 * @return t_sizemap* On sucess: Pointer to validated and populated
 * map structure. On failure: NULL (with appropiate error messages
 * printed to stderr).
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
