/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:09:06 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/21 14:40:56 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_image(void *mlx, char *path)
{
	int	width;
	int	height;

	return (mlx_xpm_file_to_image(mlx, path, &width, &height));
}

void	draw_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img_wall, x * TILE_SIZE,
			y * TILE_SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img_floor, x * TILE_SIZE,
			y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img_collectible, x * TILE_SIZE,
			y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img_player, x * TILE_SIZE,
			y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img_exit, x * TILE_SIZE,
			y * TILE_SIZE);
	else if (game->map[y][x] == 'A')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img_item_empty, x * TILE_SIZE,
			y * TILE_SIZE);
	else if (game->map[y][x] == 'K')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img_enemy, x * TILE_SIZE,
			y * TILE_SIZE);
}

