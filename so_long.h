/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:08:52 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/18 16:20:42 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_game 
{
    void    *mlx;
    void    *win;
    void    *img_wall;
    void    *img_floor;
    void    *img_collectible;
    void    *img_player;
    void    *img_exit;
    void    *img_item_empty;
    char    **map;
    int     nbr_C;
    int     nbr_C_player;
    int     flag_C;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     marche;
    int     flag;
} t_game;


#define TILE_SIZE 64

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./gnl/get_next_line.h"
#include "./printf/ft_printf.h"
#include "./minilibx-linux/mlx.h"

char	**read_map(char *file);
int		ft_count_map(char *file);
int ft_check_map(char **map, char *filename, t_game *game);
int	ft_check_rec(char **map, char *filename, t_game *game);
int		ft_check_rec2(int lo, char *filename);
int	ft_check_content_2(int E, int C, int P, t_game *game);
int	ft_check_content(char **map, t_game *game);
int	ft_check_wall(char **map);
int	ft_check_wall_sides(char **map);
int	ft_check_wall_top(char **map);
int	ft_check_zero(char **map);
void *load_image(void *mlx, char *path);
void draw_map(t_game *game);
void ft_initialize_mlx(t_game *game);
void ft_calculate_dimensions(t_game *game);
void ft_create_window(t_game *game);
int ft_close_window(t_game *game);
int	close_game(void *param);
int	key_hook(int keycode, t_game *game);
void	find_player_position(t_game *game);


#endif