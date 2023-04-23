/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:46:49 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/18 20:17:44 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*get_path(t_map map, int x, int y)
{
	char	*path;

	if (map.map[y][x] == '0')
		path = "./sprites/ground.xpm";
	else if (map.map[y][x] == '1')
		path = "./sprites/wall.xpm";
	else if (map.map[y][x] == 'P')
		path = "./sprites/player.xpm";
	else if (map.map[y][x] == 'C')
		path = "./sprites/collec.xpm";
	else
		path = "./sprites/exit.xpm";
	return (path);
}

int	render(t_game *game)
{
	char	*path;
	int		imgw;
	int		imgh;
	int		y;
	int		x;

	mlx_clear_window(game -> mlx, game -> win);
	y = -1;
	while (++y < game -> map.height)
	{
		x = -1;
		while (++x < game -> map.width)
		{
			path = get_path(game -> map, x, y);
			game -> img.img = mlx_xpm_file_to_image(game -> mlx,
					path, &imgw, &imgh);
			mlx_put_image_to_window(game -> mlx, game -> win,
				game -> img.img, x * 50, y * 50);
			render_moves(game);
		}
	}
	return (0);
}
