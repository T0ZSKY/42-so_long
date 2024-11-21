/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:21:35 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/21 15:30:34 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_gg(void)
{
	ft_printf("   ____  ____   _  __        ______  \n");
	ft_printf("  / ___|/ ___| | | \\ \\      / /  _ \\ \n");
	ft_printf(" | |  _| |  _  | |  \\ \\ /\\ / /| |_) |\n");
	ft_printf(" | |_| | |_| | |_|   \\ V  V / |  __/ \n");
	ft_printf("  \\____|\\____| (_)    \\_/\\_/  |_|     \n");
}

void	handle_key_movement(int keycode, int *new_x, int *new_y, int *moove)
{
	if (keycode == 119)
	{
		(*new_y)--;
		*moove = 1;
	}
	else if (keycode == 115)
	{
		(*new_y)++;
		*moove = 1;
	}
	else if (keycode == 97)
	{
		(*new_x)--;
		*moove = 1;
	}
	else if (keycode == 100)
	{
		(*new_x)++;
		*moove = 1;
	}
}

void	handle_collectible(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = 'A';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->marche++;
	game->nbr_c_player++;
	ft_printf("%d\n", game->marche);
	ft_printf("nombre de item joueur : %d \n", game->nbr_c_player);
	ft_printf("nombre de item joueur : %d \n", game->nbr_c);
	if (game->nbr_c == game->nbr_c_player)
		game->flag = 1;
	draw_map(game);
}

void	handle_regular_move(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->marche++;
	ft_printf("%d\n", game->marche);
	draw_map(game);
}

void	handle_move(t_game *game, int new_x, int new_y)
{
	// Si le joueur touche l'ennemi, game over
	if (game->map[new_y][new_x] == 'K') {
		ft_printf("Game Over! You were caught by the enemy.\n");
		close_game(game);
	}

	// Si le joueur touche la sortie avec tous les collectibles, finir le jeu
	if (game->map[new_y][new_x] == 'E' && game->flag == 1)
	{
		ft_gg();
		close_game(game);
	}
	else if (game->map[new_y][new_x] == 'C')
		handle_collectible(game, new_x, new_y);
	else if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'A' && game->map[new_y][new_x] != 'E')
		handle_regular_move(game, new_x, new_y);
}

