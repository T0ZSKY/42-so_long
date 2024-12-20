/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:24:06 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/21 14:09:48 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_check_rec(char **map, char *filename, t_game *game)
{
	int	i;
	int	size;
	int	tmp;

	i = 0;
	tmp = 0;
	while (map[i] != NULL)
	{
		size = ft_strlen(map[i]);
		if (size > 0 && map[i][size - 1] == '\n')
			size--;
		if (tmp == 0)
			tmp = size;
		if (tmp != size)
			return (1);
		i++;
	}
	if (ft_check_rec2(size, filename) == 1)
		return (1);
	else if (ft_check_content(map, game) == 1)
		return (1);
	else if (ft_check_wall(map) == 1)
		return (1);
	return (0);
}

int	ft_check_rec2(int lo, char *filename)
{
	int	haut;

	haut = ft_count_map(filename);
	if (haut == lo)
		return (1);
	else
		return (0);
}

int	ft_check_map(char **map, char *filename, t_game *game)
{
	if (ft_check_rec(map, filename, game) == 1)
		return (1);
	else
		return (0);
}

int	ft_check_content(char **map, t_game *game)
{
	int	i;
	int	j;
	int	e;
	int	c;
	int	p;

	j = 0;
	e = 0;
	c = 0;
	p = 0;
	while (map[j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'E')
				e++;
			else if (map[j][i] == 'P')
				p++;
			else if (map[j][i] == 'C')
				c++;
		}
		j++;
	}
	return (ft_check_content_2(e, c, p, game));
}

int	ft_check_content_2(int e, int C, int P, t_game *game)
{
	game->nbr_c = C;
	if (e != 1)
		return (1);
	else if (C < 1)
		return (1);
	else if (P != 1)
		return (1);
	return (0);
}
