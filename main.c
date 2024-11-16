/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:08:37 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/16 21:14:44 by tomlimon         ###   ########.fr       */
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
	if (!map || !validate_map(map))
		return (write(2, "Error: invalid map\n", 19), 1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, ft_strlen(map[0]) * 32, count_lines(map) * 32, "so_long");
	draw_map(mlx, win, map);
	mlx_hook(win, 17, 0, close_window, mlx);
	mlx_loop(mlx);
	return (0);
}
