#include "fdf.h"

void	ft_free_double(char *str, char **str1, int c)
{
	int i;

	i = 0;
	free(str);
	while(i < c)
	{
		free(str1[i]);
		i++;
	}
	free(str1);
}

int	ft_check_map(char *path)
{
	int		fd;
	char	*line;
	char 	*ptr;

	fd = open(path,O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening the file, %s\n", strerror(errno));
		exit(FILE_ERROR);
	}
	line = get_next_line(fd);
	ptr = get_next_line(fd);
	while(ptr)
	{
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	if (!ft_strchr(line, 'x'))
	{
		free(line);
		return (1);
	}
	return (0);
}

void	ft_copy_value(int *ar, char **tmp, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		ar[i] = ft_atoi(*tmp);
		tmp++;
		i++;
	}
}

int	word_count(char	*s, char c)
{
	int	state;
	int	count;

	count = 0;
	state = OUT;
	while (*s)
	{
		if (*s == c)
			state = OUT;
		else if (state == OUT)
		{
			count++;
			state = IN;
		}
		s++;
	}
	return (count);
}

int count_lines(char *path, int *a)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(path,O_RDONLY);
	if (fd < 0)
	{
			printf("Error opening the file, %s\n", strerror(errno));
			exit(FILE_ERROR);
	}
	line = get_next_line(fd);
	*a = word_count(line, ' ');
	while(line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}