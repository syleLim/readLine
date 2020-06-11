#include "./read_line.h"

int		ft_strlen(char *str)
{
	int i;
	
	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

int 	find_n(char *file)
{
	int i;

	if (!file)
		return (-1);
	i = -1;
	while (file[++i])
		if (file[i] == '\n')
			return (i);
	return (-1);
}

int		free_file(char *file)
{
	free(file);
	return (-1);
}
