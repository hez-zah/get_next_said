#include "get_next_line_bonus.h"

char *get_long_line(int fd,  char *long_line)
{
    char *buffer;
    char *free_lg;
    int chars_read;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    if (!long_line)
        long_line = ft_strdup("");
    while ((chars_read = read(fd , buffer , BUFFER_SIZE)) > 0)
    {
        buffer[chars_read] = '\0';
        free_lg = long_line;
        long_line = ft_strjoin(long_line, buffer);
        free(free_lg);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    return (no_read(chars_read, long_line, buffer));
}

char *get_line(char *long_line)
{
    char *str;
    int i;

    i = 0;
    while (long_line[i] != '\n' && long_line[i] != '\0')
        i++;
    if (long_line[i] == '\n')
        i++;
    str = malloc((i + 1) * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (long_line[i] != '\n' && long_line[i] != '\0')
    {
        str[i] = long_line[i];
        i++;
    }
    if (long_line[i] == '\n')
    {
        str[i] = '\n';
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *rest_long_line(char *long_line, char *line)
{
    char *str;
    size_t  len;
    size_t  i;

    len = ft_strlen(line);
    if (!long_line[len])
        return (NULL);
    str = malloc((ft_strlen(long_line) - len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (long_line[len])
        str[i++] = long_line[len++];
    str[i] = '\0';
    return (str);
}

char *get_next_line(int fd)
{
    static char *long_line[OPEN_MAX];
    char        *free_lg;
    char *line;

    if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    long_line[fd] = get_long_line(fd, long_line[fd]);
    if (!long_line[fd])
        return (NULL);
    line = get_line(long_line[fd]);
    free_lg = long_line[fd];
    long_line[fd] = rest_long_line(long_line[fd], line);
    free(free_lg);
    return (line);
}
