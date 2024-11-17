/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:24:06 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/16 22:55:02 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_check_rec(char **map, char *filename)
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
	return (0);
}

int	ft_check_rec2(int lo, char *filename)
{
	int	haut;

	haut = ft_count_map(filename);
	if (haut > lo)
		return (1);
	else if (haut == lo)
		return (1);
	else
		return (0);
}

int ft_check_map(char **map, char *filename)
{
	if (ft_check_rec(map, filename) == 1)
		return (1);
	else
		return (0);
}