/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:10:34 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/20 13:50:37 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map_file(char *file, char ***map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(*map);
		*map = NULL;
	}
	return (fd);
}

char	**read_map(char *file)
{
	int		fd;
	int		i;
	int		size;
	char	*line;
	char	**map;

	size = ft_count_map(file);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	fd = open_map_file(file, &map);
	if (!fd)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
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
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		size++;
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}
