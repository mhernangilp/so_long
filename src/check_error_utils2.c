/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:58:41 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/09 19:30:34 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static pos	get_pos(s_map map, char c)
{
	int	i;
	int	j;
	pos	pos;

	j = -1;
	pos.y = -1;
	pos.x = -1;
	while (++j < map.height)
	{
		i = -1;
		while (++i < map.width)
			if (map.map[j][i] == c)
			{
				pos.y = j;
				pos.x = i;
			}
	}
	return (pos);
}

static void	floodfill(s_map *map, int y, int x)
{
	if (y < 0 || x < 0 || y >= map -> height ||
			x >= map -> width || map -> map[y][x] == '1' ||
			map -> map[y][x] == 'F')
		return ;
	map -> map[y][x] = 'F';
	floodfill(map, y - 1, x);
	floodfill(map, y, x - 1);
	floodfill(map, y + 1, x);
	floodfill(map, y, x + 1);
}

int	check_path(s_map map)
{
	pos	Ppos;
	pos	Epos;

	Ppos = get_pos(map, 'P');
	Epos = get_pos(map, 'E');
	if (Ppos.y == -1 || Ppos.x == -1 ||
			Epos.y == -1 || Epos.x == -1)
		return (-1);
	floodfill(&map, Ppos.y, Ppos.x);
	if (map.map[Epos.y][Epos.x] != 'F')
		return (-1);
	return 0;
}
