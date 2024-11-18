
#include "so_long.h"
#include <stdio.h>

int	close_game(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	int	new_x = game->player_x;
	int	new_y = game->player_y;
	int	moove;

	moove = 0;
	if (keycode == 53) // Échap
		close_game(game);
	else if (keycode == 13)
	{
		new_y--;
		moove = 1;
	}
	else if (keycode == 1)
	{
		new_y++;
		moove = 1;
	}
	else if (keycode == 0)
	{
		new_x--;
		moove = 1;
	}
	else if (keycode == 2)
	{
		new_x++;
		moove = 1;
	}
	if (moove == 0)
		return (0);
	if (game->map[new_y][new_x] == 'E' && game->flag == 1)
	{
		ft_printf("GG ! Miner is rich !\n");
		close_game(game);
	}
	else if (game->map[new_y][new_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = 'A';
		game->map[new_y][new_x] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
		game->marche = game->marche + 1;
		game->nbr_C_player = game->nbr_C_player + 1;
		ft_printf("%d\n", game->marche);
		if (game->nbr_C == game->nbr_C_player)
			game->flag = 1;
		draw_map(game);
	}
	else if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'A'
	&& game->map[new_y][new_x] != 'E')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
		game->marche = game->marche + 1;
		ft_printf("%d\n", game->marche);
		draw_map(game);
	}
	return (0);
}

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return;
			}
			x++;
		}
		y++;
	}
}
