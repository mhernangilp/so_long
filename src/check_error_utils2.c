/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:58:41 by mhernang          #+#    #+#             */
/*   Updated: 2023/05/31 17:12:39 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_pos	get_pos(t_map map, char c)
{
	int		i;
	int		j;
	t_pos	pos;

	j = -1;
	pos.y = -1;
	pos.x = -1;
	while (++j < map.height)
	{
		i = -1;
		while (++i < map.width)
		{
			if (map.map[j][i] == c)
			{
				pos.y = j;
				pos.x = i;
			}
		}
	}
	return (pos);
}

static void	floodfill(t_map *map, int y, int x)
{
	if (y < 0 || x < 0 || y >= map -> height
		|| x >= map -> width || map -> map[y][x] == '1'
		|| map -> map[y][x] == 'F')
		return ;
	map -> map[y][x] = 'F';
	floodfill(map, y - 1, x);
	floodfill(map, y, x - 1);
	floodfill(map, y + 1, x);
	floodfill(map, y, x + 1);
}

int	check_path(t_map map)
{
	t_pos	ppos;
	t_pos	epos;

	ppos = get_pos(map, 'P');
	epos = get_pos(map, 'E');
	if (ppos.y == -1 || ppos.x == -1
		|| epos.y == -1 || epos.x == -1)
		return (-1);
	floodfill(&map, ppos.y, ppos.x);
	if (map.map[epos.y][epos.x] != 'F')
		return (-1);
	return (0);
}
