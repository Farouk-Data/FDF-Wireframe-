#include "fdf.h"
#include "get_next_line.h"



// void	ft_parse_values(int fd, char *path, t_map *map)
// {
// 	t_map	map;
// 	int		i;
// 	char	*line;
// 	char	**tmp;

// 	i = 0;
// 	map -> line_count = count_lines(fd, &map->word_count);
// 	map->map_values = (int **)malloc(map->line_count * sizeof(int *));
// 	while (i < map->line_count)
// 		map->map_values[i++] = (int *)malloc(map->word_count * sizeof(int));
// 	i = 0;
// 	fd = open(path, O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line && i < map->line_count)
// 	{
// 		tmp = ft_split(line, ' ');
// 		ft_copy_value(map->map_values[i++],tmp,map->word_count);
// 		ft_free_double(line, tmp, map->word_count);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }