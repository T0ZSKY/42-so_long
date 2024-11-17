/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inti_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:57:00 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/17 21:57:20 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_create_window(t_game *game)
{
    game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "so_long");
    if (!game->win)
    {
        write(2, "Error: MLX window creation failed\n", 34);
        exit(1);
    }
    mlx_hook(game->win, 17, 0, ft_close_window, game);
}