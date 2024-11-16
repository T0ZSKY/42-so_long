/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:10:34 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/16 21:31:56 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *file)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	while (get_next_line(fd, &line) > 0)
		map = ft_strarr_add(map, line);
	map = ft_strarr_add(map, line);
	close(fd);
	return (map);
}

char **ft_strarr_add(char **arr, char *str)
{
	int		i;
	char	**new;

	i = 0;
	while (arr && arr[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (arr && arr[i])
	{
		new[i] = arr[i];
		i++;
	}
	new[i] = str;
	new[i + 1] = NULL;
	free(arr);
	return (new);
}
