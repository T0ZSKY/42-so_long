/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:44 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/21 14:10:01 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:00:00 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/21 14:00:00 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_row(t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < game->width)
	{
		draw_tile(game, x, y);
		x++;
	}
}

void	draw_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		draw_row(game, y);
		y++;
	}
}

void	ft_initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error: MLX init failed\n", 23);
		exit(1);
	}
}

void	ft_calculate_dimensions(t_game *game)
{
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = ft_strlen(game->map[0]);
	game->width -= 1;
	game->marche = 0;
	game->nbr_c_player = 0;
	game->flag = 0;
}

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
