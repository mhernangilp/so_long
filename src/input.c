/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:20:35 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/18 20:17:40 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(t_game *game)
{
	if (game -> map.map[game -> player.y - 1][game -> player.x] == 'E')
	{
		if (game -> collec == game -> total_collec)
		{
			ft_printf("Enhorabuena !!\n");
			end_game(game);
		}
	}
	else if (game -> map.map[game -> player.y - 1][game -> player.x] != '1')
	{
		if (game -> map.map[game -> player.y - 1][game -> player.x] == 'C')
			game -> collec += 1;
		game -> map.map[game -> player.y][game -> player.x] = '0';
		game -> map.map[game -> player.y - 1][game -> player.x] = 'P';
		game -> player.y -= 1;
		game -> moves += 1;
		ft_printf("Moves -> %d\n", game -> moves);
	}
}

static void	move_down(t_game *game)
{
	if (game -> map.map[game -> player.y + 1][game -> player.x] == 'E')
	{
		if (game -> collec == game -> total_collec)
		{
			ft_printf("Enhorabuena !!\n");
			end_game(game);
		}
	}
	else if (game -> map.map[game -> player.y + 1][game -> player.x] != '1')
	{
		if (game -> map.map[game -> player.y + 1][game -> player.x] == 'C')
			game -> collec += 1;
		game -> map.map[game -> player.y][game -> player.x] = '0';
		game -> map.map[game -> player.y + 1][game -> player.x] = 'P';
		game -> player.y += 1;
		game -> moves += 1;
		ft_printf("Moves -> %d\n", game -> moves);
	}
}

static void	move_right(t_game *game)
{
	if (game -> map.map[game -> player.y][game -> player.x + 1] == 'E')
	{
		if (game -> collec == game -> total_collec)
		{
			ft_printf("Enhorabuena !!\n");
			end_game(game);
		}
	}
	else if (game -> map.map[game -> player.y][game -> player.x + 1] != '1')
	{
		if (game -> map.map[game -> player.y][game -> player.x + 1] == 'C')
			game -> collec += 1;
		game -> map.map[game -> player.y][game -> player.x] = '0';
		game -> map.map[game -> player.y][game -> player.x + 1] = 'P';
		game -> player.x += 1;
		game -> moves += 1;
		ft_printf("Moves -> %d\n", game -> moves);
	}
}

static void	move_left(t_game *game)
{
	if (game -> map.map[game -> player.y][game -> player.x - 1] == 'E')
	{
		if (game -> collec == game -> total_collec)
		{
			ft_printf("Enhorabuena !!\n");
			end_game(game);
		}
	}
	else if (game -> map.map[game -> player.y][game -> player.x - 1] != '1')
	{
		if (game -> map.map[game -> player.y][game -> player.x - 1] == 'C')
			game -> collec += 1;
		game -> map.map[game -> player.y][game -> player.x] = '0';
		game -> map.map[game -> player.y][game -> player.x - 1] = 'P';
		game -> player.x -= 1;
		game -> moves += 1;
		ft_printf("Moves -> %d\n", game -> moves);
	}
}

int	input(int key, t_game *game)
{
	(void)game;
	if (key == ESC)
		end_game(game);
	else if (key == KEY_UP)
		move_up(game);
	else if (key == KEY_DOWN)
		move_down(game);
	else if (key == KEY_LEFT)
		move_left(game);
	else if (key == KEY_RIGHT)
		move_right(game);
	else
		return (1);
	return (0);
}
