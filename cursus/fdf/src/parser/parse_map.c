/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:25:00 by sergio-jime       #+#    #+#             */
/*   Updated: 2026/05/20 12:25:00 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_elements(char *line)
{
	int	count;

	count = 0;
	while (*line)
	{
		while (*line && ft_isspace(*line))
			line++;
		if (*line && *line != '\n')
		{
			count++;
			while (*line && !ft_isspace(*line))
				line++;
		}
	}
	return (count);
}

static bool	parse_line_to_row(char *line, t_coordinates *row, int w, int r_idx)
{
	int	col;

	col = 0;
	while (col < w)
	{
		while (ft_isspace(*line))
			line++;
		if (*line == '\0' || *line == '\n')
			return (false);
		row[col] = (t_coordinates){col, r_idx, ft_atoi(line), 0xFFFFFF};
		if (*line == '-' || *line == '+')
			line++;
		while (ft_isdigit(*line))
			line++;
		if (*line == ',' && ++line)
		{
			if (*line == '0' && (*(line + 1) == 'x' || *(line + 1) == 'X'))
				line += 2;
			row[col].color = ft_atoi_base(line, 16);
			while (ft_isxdigit(*line))
				line++;
		}
		col++;
	}
	return (true);
}

static void	compute_z_bounds(t_sizemap *map)
{
	int	r;
	int	c;
	int	z;

	map->z_min = map->matrix[0][0].axis_z;
	map->z_max = map->matrix[0][0].axis_z;
	r = 0;
	while (r < map->height)
	{
		c = 0;
		while (c < map->width)
		{
			z = map->matrix[r][c].axis_z;
			if (z < map->z_min)
				map->z_min = z;
			if (z > map->z_max)
				map->z_max = z;
			c++;
		}
		r++;
	}
}

static bool	read_rows(int fd, t_sizemap *map, t_row_node **h, t_row_node **t)
{
	char		*ln;
	t_row_node	*nd;

	while (1)
	{
		ln = get_next_line(fd);
		if (!ln)
			return (map->height > 0);
		if (map->width == 0)
			map->width = count_elements(ln);
		nd = ft_calloc(1, sizeof(t_row_node));
		if (nd && count_elements(ln) == map->width)
			nd->row = ft_calloc(map->width, sizeof(t_coordinates));
		if (!nd || !nd->row || !parse_line_to_row(ln, nd->row, map->width, map->height))
		{
			if (nd)
				free(nd->row);
			return (free(nd), free(ln), false);
		}
		if (!*h)
			*h = nd;
		else
			(*t)->next = nd;
		*t = nd;
		map->height += (free(ln), 1);
	}
}

t_sizemap	*validate_map(int fd, t_sizemap *map)
{
	t_row_node	*head;
	t_row_node	*tail;
	int			i;

	head = NULL;
	tail = NULL;
	if (!map)
		map = ft_calloc(1, sizeof(t_sizemap));
	if (!map)
		return (NULL);
	if (!read_rows(fd, map, &head, &tail))
		return (cleanup_list(head, true), free(map),
			print_error("Error Invalid Map\n"), NULL);
	map->matrix = ft_calloc(map->height, sizeof(t_coordinates *));
	if (!map->matrix)
		return (cleanup_list(head, true), free(map), NULL);
	i = 0;
	while (head)
	{
		map->matrix[i++] = head->row;
		tail = head->next;
		free(head);
		head = tail;
	}
	compute_z_bounds(map);
	return (map);
}
