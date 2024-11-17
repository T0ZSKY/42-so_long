/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:08:37 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/16 22:50:06 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	void	*mlx;
	void	*win;

	if (argc != 2)
		return (write(2, "Usage: ./so_long map.ber\n", 25), 1);
	map = read_map(argv[1]);
	if (!map || !map[0])
    return (write(2, "Error: map\n", 11), 1);
	if (ft_check_map(map, argv[1]) == 1)
	{
		write(1, "Error map not good\n", 19);
	}
	else
		write(1, "map good\n", 9);


	return (0);
}
