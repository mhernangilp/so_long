/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:57:01 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/18 20:17:47 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_collec(t_map map)
{
	int	collec;
	int	x;
	int	y;

	y = -1;
	collec = 0;
	while (++y < map.height)
	{
		x = -1;
		while (++x < map.width)
			if (map.map[y][x] == 'C')
				collec += 1;
	}
	return (collec);
}

void	init_game(t_game *game, char **argv)
{
	game -> map = read_map(argv[1]);
	game -> mlx = mlx_init();
	game -> win = mlx_new_window(game -> mlx, game -> map.width * 50,
			game -> map.height * 50, "so_long");
	game -> player = get_pos(game -> map, 'P');
	game -> img.img = mlx_new_image(game -> mlx, 50, 50);
	game -> img.addr = mlx_get_data_addr(game -> img.img,
			&game -> img.bits_per_pixel,
			&game -> img.line_length, &game -> img.endian);
	game -> moves = 0;
	game -> total_collec = get_collec(game -> map);
	game -> collec = 0;
}
