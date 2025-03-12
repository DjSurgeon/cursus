/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:51:04 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/03/13 00:02:43 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *clean_buffer(char *buffer)
{
    char *newline_pos;
    char *remaining;

    newline_pos = ft_strchr(buffer, '\n');
    if (newline_pos)
    {
        remaining = ft_strdup(newline_pos + 1); // Conserva lo después de '\n'
        free(buffer);
        return (remaining);
    }
    free(buffer); // Si no hay '\n', limpiar buffer
    return (NULL);
}

char *extract_line(char *buffer)
{
    char *newline_pos;
    char *line;

    newline_pos = ft_strchr(buffer, '\n');
    if (newline_pos)
        line = ft_substr(buffer, 0, newline_pos - buffer + 1); // Incluye '\n'
    else
        line = ft_strdup(buffer); // Última línea sin '\n'
    return (line);
}

char *read_line(int fd, char **buffer)
{
    char *temp_read;
    int bytes_read;

    temp_read = malloc(BUFFER_SIZE + 1);
    if (!temp_read)
        return (NULL);

    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, temp_read, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(temp_read);
            return (NULL);
        }
        temp_read[bytes_read] = '\0';
        *buffer = ft_strjoin(*buffer, temp_read);

        if (ft_strchr(*buffer, '\n') || bytes_read == 0)
            break;
    }
    free(temp_read);
    return (*buffer);
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!buffer)
        buffer = ft_strdup("");
    if (!read_line(fd, &buffer) || !*buffer)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    line = extract_line(buffer);
    buffer = clean_buffer(buffer);
    return (line);
}
int main(void)
{
    char *gnl;
    int fd;

    fd = open("hello.txt", O_RDONLY);
    while ((gnl = get_next_line(fd)) != NULL)
    {
        printf("%s", gnl);
        free(gnl);
    }
    close(fd);
    return (0);
}