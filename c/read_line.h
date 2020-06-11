#ifndef READ_LINE_H
# define READ_LINE_H
# include <unistd.h>
# include <stdlib.h>
//for testing
# include <stdio.h>

# define MAX_FD			500
# define BUFFER_SIZE	200

//utils
int		ft_strlen(char *str);
int 	find_n(char *file);
char	*strjoin(char *s1, char *s2, int s2_len);
int		free_file(char *file);

int		read_line(int fd, char **line);

#endif