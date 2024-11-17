/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:08:52 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/16 22:55:29 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include "./gnl/get_next_line.h"
#include "./printf/ft_printf.h"
#include "./minilibx-linux/mlx.h"

char	**read_map(char *file);
int		ft_count_map(char *file);
int 	ft_check_map(char **map, char *filename);
int		ft_check_rec(char **map, char *filename);
int		ft_check_rec2(int lo, char *filename);

#endif