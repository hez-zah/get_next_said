#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define OPEN_MAX 100;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

size_t	ft_get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char    *no_read(int chars_read, char *long_line, char *buffer);




#endif
