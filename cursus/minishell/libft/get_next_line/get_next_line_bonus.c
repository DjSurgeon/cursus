/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:32:16 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/05/22 13:51:18 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
Read from FD and save in store, keeping any possible leftover
from previous calls (ft_strjoin).
 */
static char	*ft_read_n_store(int fd, char *store)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(store), store = NULL, NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(store, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(store), store = NULL, NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(store, buffer);
		if (!temp)
			return (free(buffer), free(store), store = NULL, NULL);
		free(store);
		store = ft_strdup(temp);
		free(temp);
	}
	free(buffer);
	return (store);
}

/* 
Extract our line (if there is a \n) from our store.
 */
static char	*ft_get_line(char *store)
{
	char	*line;
	size_t	i;

	if (!store)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i ++;
	if (store[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, store, i + 1);
	return (line);
}

/* 
Organise our store. If there is any leftover after extracting
our previous line, we empty that first part and keep the rest.
If store is empty, we clear it so it can be reinitialized in
the next call of get_next_line.
 */
static char	*ft_store_cleaner(char *store)
{
	char	*leftover;
	size_t	i;

	if (!store || *store == '\0')
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i ++;
	if (store[i] == '\n')
		i++;
	leftover = ft_strdup(store + i);
	if (!leftover)
		return (NULL);
	free(store);
	store = leftover;
	return (store);
}

/*
BONUS:
- MAX_FD that our computer can manage at the same time, 
checked with command "ulimit -n" : 1024. Defined in library. 

store: our static string where we keep what we read (including lines or not).
* As bonus, it will be an array of arrays to keep track of multiple FDs
at the same time.

line: to keep our full line (if it ends with \n or eof)

- Check if our FD is ok. 
- If store isn't initialized (or has been freed), initialize with empty string.

1) Start reading and storing: in ft_read_n_store we'll keep reading 
until we find "\n" or until we finish document. Maybe this is a problem.
2) If there's been a problem and store = NULL, we exit. 
If store is empty, we exit.
3) If there's not a \n in our store, it's our last line, so we return it.
4) If non of these conditions are met, we extract our line from store,
and we clean our store(keep leftover or empty it).
 */
char	*get_next_line(int fd)
{
	static char	*store[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if (!store[fd])
		store[fd] = ft_strdup("");
	store[fd] = ft_read_n_store(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	if (*store[fd] == '\0')
		return (free(store[fd]), store[fd] = NULL, NULL);
	if (!ft_strchr(store[fd], '\n'))
	{
		line = ft_strdup(store[fd]);
		free(store[fd]);
		store[fd] = NULL;
		return (line);
	}
	line = ft_get_line(store[fd]);
	store[fd] = ft_store_cleaner(store[fd]);
	return (line);
}
