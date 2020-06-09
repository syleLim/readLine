#include "./read_line.h"
#include <stdio.h>

int 	find_n(char *file)
{
	int i;

	if (!file)
		return (0);
	i = -1;
	while (file[++i])
		if (file[i] == '\n')
			return (i);
	return (0);
}

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

char	*strjoin(char *s1, char *s2, int s2_len)
{
	char	*str;
	int		s1_len;
	int		i;

	s1_len = ft_strlen(s1);
	if (!(str = malloc(sizeof(char) *
			(s1_len + s2_len + 1))))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[s1_len + i] = s2[i];
	str[s1_len + i] = 0;
	//hmm ...
	free(s1);
	//
	return (str);
}

char	*read_file(char *file, int fd, int *code)
{
	char	buf[BUFFER_SIZE + 1];
	
	if (!file)
	{
		if (!(file = (char *)malloc(sizeof(char))))
			return (NULL);
		*file = 0;
	}
	if ((*code = read(fd, buf, BUFFER_SIZE)) > 0)
		file = strjoin(file, buf, *code);
	return (file);
}

char	*fill_line(char **line, char *file, int len, int *code)
{
	char	*new_file;
	int		i;
	int		file_len;

	file_len = ft_strlen(file); 
	i = -1;
	while (++i < len)
		(*line)[i] = file[i];
	(*line)[i] = 0;
	if (file[i] == '\n')
		len++;
	if (!(new_file = malloc(sizeof(char) *
			(file_len - len + 1))))
	{
		*code = -1;
		return (NULL);
	}
	i = -1;
	while (++i < file_len - len)
		new_file[i] = file[len + i];
	free(file);
	new_file[i] = 0;
	return (new_file);
}

int		free_all(char *files[MAX_FD])
{
	int i;

	i = -1;
	while (++i < MAX_FD)
	{
		if (files[i])
			free(files[i]);
	}
	return (-1);
}

int		read_line(int fd, char **line)
{
	static char 	*files[MAX_FD];
	int				code;
	int				len;

	code = 1;
	while (!(len = find_n(files[fd])))
	{
		files[fd] = read_file(files[fd], fd, &code);
		if (code == -1 || files[fd] == NULL)
			return (free_all(files));
		if (code == 0)
			break;
	}
	files[fd] = fill_line(line, files[fd], len, &code);
	if (code == 0 && files[fd])
		free(files[fd]);
	if (code == -1)
		return (free_all(files));
	return (code < 1 ? code : 1);
}