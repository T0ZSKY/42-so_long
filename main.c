/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:08:37 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/16 21:34:23 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	void	*mlx;
	void	*win;

	if (argc != 2)
		return (write(2, "Usage: ./so_long map.ber\n", 25), 1);
	map = read_map(argv[1]);
	if (!map || !validate_map(map))
		return (write(2, "Error: invalid map\n", 19), 1);
	ft_printf("Map: %s\n", map[0]);
	return (0);
}
