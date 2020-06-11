#include <stdio.h>
#include <fcntl.h>
#include "./read_line.h"

int main(int args, char *argv[])
{
	char *line;
	int fds[args - 1];
	int x;

	for (int i = 1; i < args; i++)
		fds[i - 1] = open(argv[i], O_RDONLY);
	
	line = malloc(sizeof(char) * 100);

	while ((x = read_line(fds[0], &line) > 0))
		printf("%d : %s\n", x, line);
	printf("last %d : %s\n", x, line);
	
	// x = read_line(fds[0], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[1], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[2], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[1], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[2], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[0], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[0], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[1], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[1], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[2], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[2], &line);
	// printf("%d : %s\n", x, line);
	// x = read_line(fds[0], &line);
	// printf("%d : %s\n", x, line);

	free(line);
	return (0);
}