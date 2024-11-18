/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:08:37 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/18 14:35:33 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (write(2, "Usage: ./so_long map.ber\n", 25), 1);
	game.map = read_map(argv[1]);
	if (!game.map || !game.map[0])
		return (write(2, "Error: invalid map\n", 19), 1);
	if (ft_check_map(game.map, argv[1], &game) == 1)
		return (write(2, "Error: invalid map structure\n", 30), 1);
	ft_calculate_dimensions(&game);
	ft_initialize_mlx(&game);
	ft_create_window(&game);

	game.img_wall = load_image(game.mlx, "./assets/wall.xpm");
	game.img_floor = load_image(game.mlx, "./assets/floor.xpm");
	game.img_collectible = load_image(game.mlx, "./assets/item.xpm");
	game.img_player = load_image(game.mlx, "./assets/player.xpm");
	game.img_exit = load_image(game.mlx, "./assets/exit.xpm");
    game.img_item_empty = load_image(game.mlx, "./assets/item_empty.xpm");
	if (!game.img_wall || !game.img_floor || !game.img_collectible
		|| !game.img_player || !game.img_exit)
		return (write(2, "Error: Image loading failed\n", 28), 1);
	draw_map(&game);
    find_player_position(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
