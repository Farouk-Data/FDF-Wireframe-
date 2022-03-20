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

void	check_fd(int fd)
{
	if (fd < 0)
	{
			ft_printf("Error opening the file, %s\n", strerror(errno));
			exit(FILE_ERROR);
	}
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

int	word_count1(char *s, char c1, char c2)
{
	int	state;
	int	count;

	count = 0;
	state = OUT;
	while (*s)
	{
		if (*s == c1 || *s == c2)
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
	check_fd(fd);
	line = get_next_line(fd);
	*a = word_count1(line, ' ', '\n');
	while(line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}