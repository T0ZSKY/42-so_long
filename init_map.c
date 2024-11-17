/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:09:06 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/17 21:57:08 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *load_image(void *mlx, char *path)
{
    int width;
    int height;

    return mlx_xpm_file_to_image(mlx, path, &width, &height);
}

void draw_map(t_game *game)
{
    int x, y;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == '1') // Mur
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == '0') // Sol
                mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'C') // Collectible
                mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'P') // Joueur
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'E') // Sortie
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

void ft_initialize_mlx(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        write(2, "Error: MLX init failed\n", 23);
        exit(1);
    }
}

void ft_calculate_dimensions(t_game *game)
{
    game->height = 0;
    while (game->map[game->height])
        game->height++;
    game->width = ft_strlen(game->map[0]);

    // Réduction de la largeur
    game->width = game->width - 1;
}

int ft_close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

