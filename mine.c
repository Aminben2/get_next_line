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
    line = remainder ? ft_strdup(remainder) : ft_strdup("");
    free(remainder);
    remainder = NULL;
    while ((new_line_index = ft_strchr(line, '\n')) == -1)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes <= 0)
        {
            free(line);
            if (bytes == 0 && *buffer)
                return (buffer);
            return (NULL);
        }
        else
            buffer[bytes] = '\0';
        tmp = line;
        line = ft_strjoin(tmp, buffer);
        free(tmp);
        free(buffer);
        buffer = NULL;
        tmp = NULL;
    }
    remainder = ft_substr(line, new_line_index + 1, ft_strlen(line) - new_line_index + 1);
    return (ft_substr(line, 0, new_line_index + 1));
}