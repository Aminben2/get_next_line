/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:36:14 by mbenomar          #+#    #+#             */
/*   Updated: 2024/11/19 16:42:58 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *remainder;
    char *buffer;
    char *line;
    char *tmp;
    int bytes;
    int new_line_index;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    buffer[BUFFER_SIZE] = '\0';
    if (read(fd, buffer, BUFFER_SIZE) <= 0)
        return (free(buffer), NULL);
    line = remainder ? ft_strdup(remainder) : ft_strdup("");
    free(remainder);
    remainder = NULL;
    while ((new_line_index = ft_strchr(line, '\n')) == -1)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        printf(" bytes : %d\n", bytes);
        if (bytes <= 0)
        {
            free(line);
            if (bytes == 0 && *buffer)
                return (buffer);
            return (NULL);
        }
        else
            buffer[bytes] = '\0';
        printf("buffer : %s\n", buffer);
        printf("line before join : %s\n", line);

        tmp = line;
        printf("tmp : %s\n", tmp);
        line = ft_strjoin(tmp, buffer);
        printf("line after join : %s\n", line);
        free(tmp);
        if (!line)
            return (free(buffer), NULL);
        printf("line after after join : %s\n", line);
        printf("index : %d\n", new_line_index);
        printf("-------------------------------\n");
    }
    free(buffer);
    remainder = ft_substr(line, new_line_index + 1, ft_strlen(line) - new_line_index + 1);
    return (ft_substr(line, 0, new_line_index + 1));
}