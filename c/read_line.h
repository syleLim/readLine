#ifndef READ_LINE_H
# define READ_LINE_H
# include <unistd.h>
# include <stdlib.h>

# define MAX_FD			500
# define BUFFER_SIZE	16

int		read_line(int fd, char **line);

#endif