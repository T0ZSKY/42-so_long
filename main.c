/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:52:04 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/21 13:52:07 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_arguments(int argc)
{
	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 25);
		return (1);
	}
	return (0);
}

int	validate_map(t_game *game, char *map_path)
{
	game->map = read_map(map_path);
	if (!game->map || !game->map[0])
	{
		write(2, "Error: invalid map\n", 19);
		return (1);
	}
	if (ft_check_map(game->map, map_path, game) == 1)
	{
		write(2, "Error: invalid map structure\n", 30);
		return (1);
	}
	return (0);
}

int	initialize_graphics(t_game *game)
{
	ft_calculate_dimensions(game);
	ft_initialize_mlx(game);
	ft_create_window(game);
	game->img_wall = load_image(game->mlx, "./assets/wall.xpm");
	game->img_floor = load_image(game->mlx, "./assets/floor.xpm");
	game->img_collectible = load_image(game->mlx, "./assets/item.xpm");
	game->img_player = load_image(game->mlx, "./assets/player.xpm");
	game->img_exit = load_image(game->mlx, "./assets/exit.xpm");
	game->img_item_empty = load_image(game->mlx, "./assets/item_empty.xpm");
	if (!game->img_wall || !game->img_floor || !game->img_collectible
		|| !game->img_player || !game->img_exit)
	{
		write(2, "Error: Image loading failed\n", 28);
		return (1);
	}
	return (0);
}

void	setup_hooks_and_loop(t_game *game)
{
	draw_map(game);
	find_player_position(game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 1L << 17, (int (*)())close_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (validate_arguments(argc))
		return (1);
	if (validate_map(&game, argv[1]))
		return (1);
	if (initialize_graphics(&game))
		return (1);
	setup_hooks_and_loop(&game);
	return (0);
}
