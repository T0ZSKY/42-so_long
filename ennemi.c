/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:33:29 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/21 16:10:48 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *game)
{
	int	dx = game->player_x - game->enemy_x;
	int	dy = game->player_y - game->enemy_y;

	// Déplacement en X
	if (dx > 0 && game->map[game->enemy_y][game->enemy_x + 1] != '1' &&
		game->map[game->enemy_y][game->enemy_x + 1] != 'E' &&
		game->map[game->enemy_y][game->enemy_x + 1] != 'A' &&
		game->map[game->enemy_y][game->enemy_x + 1] != 'C' &&
		game->map[game->enemy_y][game->enemy_x + 1] != 'K') {
		if (game->map[game->enemy_y][game->enemy_x + 1] == 'P') {
			write(1, "Game Over! The enemy touched the player!\n", 41);
			exit(0);
		}
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y][game->enemy_x + 1] = 'K';
		game->enemy_x++;
	} else if (dx < 0 && game->map[game->enemy_y][game->enemy_x - 1] != '1' && 
		game->map[game->enemy_y][game->enemy_x - 1] != 'E' &&
		game->map[game->enemy_y][game->enemy_x - 1] != 'A' &&
		game->map[game->enemy_y][game->enemy_x - 1] != 'C' &&
		game->map[game->enemy_y][game->enemy_x - 1] != 'K') {
		if (game->map[game->enemy_y][game->enemy_x - 1] == 'P') {
			write(1, "Game Over! The enemy touched the player!\n", 41);
			exit(0);
		}
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y][game->enemy_x - 1] = 'K';
		game->enemy_x--;
	}

	// Déplacement en Y
	if (dy > 0 && game->map[game->enemy_y + 1][game->enemy_x] != '1' && 
		game->map[game->enemy_y + 1][game->enemy_x] != 'E' &&
		game->map[game->enemy_y + 1][game->enemy_x] != 'A' &&
		game->map[game->enemy_y + 1][game->enemy_x] != 'C' &&
		game->map[game->enemy_y + 1][game->enemy_x] != 'K') {
		if (game->map[game->enemy_y + 1][game->enemy_x] == 'P') {
			write(1, "Game Over! The enemy touched the player!\n", 41);
			exit(0);
		}
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y + 1][game->enemy_x] = 'K';
		game->enemy_y++;
	} else if (dy < 0 && game->map[game->enemy_y - 1][game->enemy_x] != '1' && 
		game->map[game->enemy_y - 1][game->enemy_x] != 'E' &&
		game->map[game->enemy_y - 1][game->enemy_x] != 'A' &&
		game->map[game->enemy_y - 1][game->enemy_x] != 'C' &&
		game->map[game->enemy_y - 1][game->enemy_x] != 'K') {
		if (game->map[game->enemy_y - 1][game->enemy_x] == 'P') {
			write(1, "Game Over! The enemy touched the player!\n", 41);
			exit(0);
		}
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y - 1][game->enemy_x] = 'K';
		game->enemy_y--;
	}
}



void	place_enemy(t_game *game)
{
	int x, y;

	// Cherche une case vide pour l'ennemi
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
			{
				game->enemy_x = x;
				game->enemy_y = y;
				game->map[y][x] = 'K';
				return ;
			}
			x++;
		}
		y++;
	}
}
