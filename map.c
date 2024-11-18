
#include "so_long.h"

char	**read_map(char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		size;
	char	**map;

	size = ft_count_map(file);
	if (size <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	ft_count_map(char *file)
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		size++;
	}
	close(fd);
	return (size);
}
