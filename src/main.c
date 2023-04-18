/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:59:00 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/18 20:17:38 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>

int	main(int args, char **argv)
{
	s_game	game;

	if (check_error(args, argv))
		return (-1);
	init_game(&game, argv);
	mlx_hook(game.win, 2, 1L<<0, input, (void *)&game);
	mlx_loop_hook(game.mlx, render, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
