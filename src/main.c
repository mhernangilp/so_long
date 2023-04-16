/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:59:00 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/16 21:39:19 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close_win(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(int args, char **argv)
{
	t_vars vars;
	t_data	img;
	int i;

	if (check_error(args, argv))
		return (-1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	i = -1;
	while (++i < 100)
	{
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
