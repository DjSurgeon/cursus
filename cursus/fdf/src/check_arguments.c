/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:55:52 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/30 11:09:48 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_extension(char *finalpath, int fd)
{
	char	*line;

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
				exit(EXIT_SUCCESS);
			}
			ft_printf("%s", line);
			free(line);
		}
	}
}

void	open_map(char *str)
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
