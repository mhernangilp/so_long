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

int	main(int args, char **argv)
{
	t_game	game;

	if (check_error(args, argv))
		return (-1);
	init_game(&game, argv);
	render(&game);
	mlx_hook(game.win, 2, 1L << 0, input, (void *) &game);
	mlx_hook(game.win, 17, 1L << 0, end_game, (void *) &game);
	mlx_loop(game.mlx);
	return (0);
}
