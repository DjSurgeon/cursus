/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:46:06 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/07/28 18:50:16 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @file create_map.c
 * @brief Parses and assigns coordinate values to the map matrix.
 * Processes a line from the map file to extract and store:
 * - X & Y grid positions (based on matrix indexes).
 * - Z elevation values (parsed from input).
 * - Color values (either specified or default white).
 * @note Expect coordinates in format 'z' or 'z,color'.
 * @note Uses default white (FFFFFF) if no color specified.
 * @note Handles hexadecimal color values (with 0x prefix).
 * @param map Pointer to initialized t_sizemap structure with allocated matrix.
 * @param line String containing space-separated coordinate data.
 * @param row Current matrix row being processed.
 * @return t_sizemap* On success: Pointer to updated map structure,
 * on failure: NULL.
 * @warning Map matrix must be pre-allocated.
 * @warning Line must match expected coordinate format.
 */
static t_sizemap	*set_coordinates(t_sizemap *map, char *line, int row)
{
	char	**axis_z;
	char	**color;
	int		col;

	col = 0;
	axis_z = ft_split(line, 32);
	if (!axis_z)
		return (free(line), NULL);
	while (col < map->width)
	{
		color = ft_split(axis_z[col], ',');
		if (!color)
			return (free_matrix(axis_z), free(line), NULL);
		map->matrix[row][col].axis_x = col;
		map->matrix[row][col].axis_y = row;
		map->matrix[row][col].axis_z = ft_atoi(color[0]);
		if (!color[1])
			map->matrix[row][col].color = ft_atoi_base("FFFFFF", 16);
		else
			map->matrix[row][col].color = ft_atoi_base(color[1] + 2, 16);
		free_matrix(color);
		col++;
	}
	free_matrix(axis_z);
	return (map);
}

/**
 * @file create_map.c
 * @brief Read and parses coordinate data from map file.
 * Processes the map file line by line, extracting and storing coordinate
 * values in the pre-allocated matrix. Handles both elevation and color data.
 * @note Reads until EOF or error occurs.
 * @note Each line must match the expected coordinate format.
 * @param fd Valid file descriptor for the opened map file.
 * @param map Pointer to initialized t_sizemap structure with allocated matrix.
 * @return t_sizemap* On success: Pointer to populated map structure,
 * on failure: NULL.
 * @warning File descriptor must be valid and properly positioned.
 * @warning Map structure must have allocated matrix.
 */
static t_sizemap	*read_coordinates(int fd, t_sizemap *map)
{
	char	*line;
	int		row;

	line = NULL;
	row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			return (map);
		}
		if (!set_coordinates(map, line, row))
			return (false);
		free(line);
		row++;
	}
	return (map);
}

/**
 * @file create_map.c
 * @brief Allocates a 2D matrix for storing map coordinates.
 * Dynamically allocates memory for a height x width matrix coordinates.
 * Performs complete initialization and cleanup if allocation fails
 * at any stage.
 * @note Performs row-by-row allocation with immediate cleanup on failure.
 * @note Sets matrix pointer to NULL on complete failure.
 * @note Prints descriptive error messages for allocation failures.
 * @param map Pointer to t_sizemap structure containing:
 * - Height: Number of rows to allocate.
 * - Width: Number or columns to allocate.
 * - Matrix: Pointer to be initialized.
 * @return bool true If allocation succeeds for entire matrix.
 * @return bool false If any allocation fails (with full cleanup).
 * @warning The map structure must have a valid height and width values > 0.
 */
static bool	allocate_matrix(t_sizemap *map)
{
	int	row;

	row = 0;
	map->matrix = ft_calloc(map->height, sizeof(t_coordinates *));
	if (!map->matrix)
	{
		print_error("Error: Memory allocation in matrix rows\n");
		return (false);
	}
	while (row < map->height)
	{
		map->matrix[row] = ft_calloc(map->width, sizeof(t_coordinates));
		if (!map->matrix[row])
		{
			print_error("Error: Memory allocation in matrix columns\n");
			free_structure(map->matrix, map->height);
			map->matrix = NULL;
			return (false);
		}
		row++;
	}
	return (true);
}

/**
 * @file create_map.c
 * @brief Creates and populates the coordinate matrix from map file.
 * Orchestrates the complete coordinate maatrix creation process:
 * 1 - Allocates memory for the 2D coordinate matrix.
 * 2 - Reads and parses coordinate values from the file.
 * 3 - Handles resource cleanup on failure.
 * @note Manage all memory allocation for coordinate storage.
 * @note Close file descriptor before returning.
 * @note Performs complete cleanup on any failure.
 * @param map Pointer to initialized t_sizemap structure.
 * @param fd Valid file descriptor for the opened map file.
 * @return t_sizemap* On success: Pointer to populated map structure,
 * on failure: NULL.
 * @warning The map structure must be properly initialized.
 * @warning The file descriptor must be valid and readable.
 */
t_sizemap	*create_coordinates(t_sizemap *map, int fd)
{
	if (!allocate_matrix(map))
		return (NULL);
	map = read_coordinates(fd, map);
	if (!read_coordinates(fd, map))
		return (free_structure(map->matrix, map->height), close(fd),
			print_error("Error: Invalid coordinates\n"), NULL);
	close(fd);
	return (map);
}
