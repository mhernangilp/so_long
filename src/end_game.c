/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:37:08 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/23 15:42:37 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_map *map)
{
	int	y;

	y = -1;
	while (++y < map ->height)
		free(map -> map[y]);
	free(map -> map);
}

int	end_game(t_game *game)
{
	free_map(&game -> map);
	exit(0);
}
