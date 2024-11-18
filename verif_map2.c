/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   verif_map2.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tomlimon <tomlimon@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/17 13:57:35 by tomlimon		  #+#	#+#			 */
/*   Updated: 2024/11/18 14:21:02 by tomlimon		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall_top(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_wall_sides(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[i])
		i++;
	i--;
	j = 0;
	while (map[i][j] && map[i][j] != '\n')
	{
		if (map[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_wall(char **map)
{
	if (ft_check_wall_top(map) == 1)
		return (1);
	if (ft_check_wall_sides(map) == 1)
		return (1);
	if (ft_check_zero(map) == 1)
		return (1);
	return (0);
}

int	ft_check_zero(char **map)
{
	int	i;
	int	j;

	j = 1;
	while (map[j + 1])
	{
		i = 1;
		while (map[j][i] && map[j][i + 1])
		{
			if (map[j][i] != '0' && map[j][i] != 'E' && map[j][i] != 'P'
				&& map[j][i] != 'C' && map[j][i] != '1')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
