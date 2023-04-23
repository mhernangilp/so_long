/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:01:46 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/23 17:01:48 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

static char	*get_path(int n)
{
	char	*path;

	if (n == 0)
		path = "./numbers/0.xpm";
	else if (n == 1)
		path = "./numbers/1.xpm";
	else if (n == 2)
		path = "./numbers/2.xpm";
	else if (n == 3)
		path = "./numbers/3.xpm";
	else if (n == 4)
		path = "./numbers/4.xpm";
	else if (n == 5)
		path = "./numbers/5.xpm";
	else if (n == 6)
		path = "./numbers/6.xpm";
	else if (n == 7)
		path = "./numbers/7.xpm";
	else if (n == 8)
		path = "./numbers/8.xpm";
	else
		path = "./numbers/9.xpm";
	return (path);
}

void	render_moves(t_game *game)
{
	char	*path;
	int		imgw;
	int		imgh;
	int		num;
	int		desv;

	num = game -> moves;
	desv = 20;
	while (num > 9)
	{
		path = get_path(num % 10);
		game -> img.img = mlx_xpm_file_to_image(game -> mlx,
				path, &imgw, &imgh);
		mlx_put_image_to_window(game -> mlx, game -> win,
			game -> img.img, game -> map.width * 50 - desv, 10);
		num /= 10;
		desv += 15;
	}
	path = get_path(num % 10);
	game -> img.img = mlx_xpm_file_to_image(game -> mlx,
			path, &imgw, &imgh);
	mlx_put_image_to_window(game -> mlx, game -> win,
		game -> img.img, game -> map.width * 50 - desv, 10);
}