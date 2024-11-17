/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:10:34 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/16 22:38:54 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

char **read_map(char *file)
{
    int     fd;
    char    *line;
    int     i;
	int		size;
    char    **map;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
	size = ft_count_map(file);
    map = malloc(sizeof(char *) * size);
    if (!map)
        return (NULL);
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
	int fd2;
	int	size;
	char *line;

	size = 0;
	fd2 = open(file, O_RDONLY);
	if (fd2 <= 0)
		return (0);
	while((line = get_next_line(fd2)) != NULL)
		size++;
	return (size);
}