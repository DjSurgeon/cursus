/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:55:52 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/30 14:15:09 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_coordinate(char *line, t_sizemap *map)
{
	char			**axis_z;
	int				i;
	static int		j = 1;

	i = 0;
	axis_z = ft_split(line, 32);
	while (axis_z[i])
	{
		free(axis_z[i]);
		i++;
	}
	map->width = i;
	map->heigth = j++;
	if (map->check_width != 0 && map->check_width != map->width)
	{
		perror("Error different width map");
		exit (EXIT_FAILURE);
	}
	map->check_width = map->width;
	free(axis_z);
}

static void	check_extension(char *finalpath, int fd)
{
	t_sizemap	*map;
	char		*line;

	map = NULL;
	map = malloc(sizeof(t_sizemap));
	if (ft_strnstr(finalpath, ".fdf", ft_strlen(finalpath)) == NULL)
	{
		perror("Error extension");
		free(finalpath);
		exit (EXIT_FAILURE);
	}
	else
	{
		while (1)
		{
			line = get_next_line(fd);
			if (line == NULL)
			{
				free(finalpath);
				// TODO: eje z
				ft_printf("width %d, heigth %d\n", map->width, map->heigth);
				free(map);
				exit(EXIT_SUCCESS);
			}
			check_coordinate(line, map);
			free(line);
		}
	}
}

void	check_map(char *str)
{
	int		fd;
	char	*path = "../fdf/maps/";
	char	*file = str;
	char	*finalpath;

	finalpath = ft_strjoin(path, file);
	fd = open(finalpath, O_RDONLY);
	if (fd == -1)
	{
		perror("Error open(): ");
		free(finalpath);
		exit(EXIT_FAILURE);
	}
	else
		check_extension(finalpath, fd);
	close(fd);
}
