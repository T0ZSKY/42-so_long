/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:08:37 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/17 21:28:45 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (write(2, "Usage: ./so_long map.ber\n", 25), 1);
    game.map = read_map(argv[1]);
    if (!game.map || !game.map[0])
        return (write(2, "Error: map\n", 11), 1);
    if (ft_check_map(game.map, argv[1]) == 1)
        return (write(2, "Error map not good\n", 19), 1);
    ft_initialize_mlx(&game);
    ft_calculate_dimensions(&game);
    ft_create_window(&game);
    game.img_wall = load_image(game.mlx, "./assets/wall.xpm");
    game.img_floor = load_image(game.mlx, "./assets/floor.xpm");
    game.img_collectible = load_image(game.mlx, "./assets/item.xpm");
    game.img_player = load_image(game.mlx, "./assets/player.xpm");
    game.img_exit = load_image(game.mlx, "./assets/exit.xpm");
    if (!game.img_wall || !game.img_floor || !game.img_collectible || !game.img_player || !game.img_exit)
        return (write(2, "Error: Image loading failed\n", 27), 1);
    draw_map(&game);
    mlx_loop(game.mlx);
    return (0);
}
