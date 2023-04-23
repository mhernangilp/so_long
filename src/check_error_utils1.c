/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:45:45 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/09 18:46:06 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_characters(t_map map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map.height)
	{
		i = -1;
		while (++i < map.width)
			if (map.map[j][i] != '0' && map.map[j][i] != '1' &&
					map.map[j][i] != 'C' && map.map[j][i] != 'E' &&
					map.map[j][i] != 'P')
				return (-1);
	}
	return (0);
}

int	check_player(t_map map)
{
	int	found;
	int	i;
	int	j;

	j = -1;
	found = 0;
	while (++j < map.height)
	{
		i = -1;
		while (++i < map.width)
			if (map.map[j][i] == 'P')
				found += 1;
	}
	if (found != 1)
		return (-1);
	return (0);
}

int	check_exit(t_map map)
{
	int	found;
	int	i;
	int	j;

	j = -1;
	found = 0;
	while (++j < map.height)
	{
		i = -1;
		while (++i < map.width)
			if (map.map[j][i] == 'E')
				found += 1;
	}
	if (found != 1)
		return (-1);
	return (0);
}

int	check_coleccionable(t_map map)
{
	int	found;
	int	i;
	int	j;

	j = -1;
	found = 0;
	while (++j < map.height)
	{
		i = -1;
		while (++i < map.width)
			if (map.map[j][i] == 'C')
				found += 1;
	}
	if (found == 0)
		return (-1);
	return (0);
}

int	check_walls(t_map map)
{
	int	j;
	int	wrong;

	j = -1;
	wrong = 0;
	while (++j < map.width)
		if (map.map[0][j] != '1')
			wrong = 1;
	j = 0;
	while (++j < map.height - 1)
		if (map.map[j][0] != '1' || map.map[j][map.width - 1] != '1')
			wrong = 1;
	j = -1;
	while (++j < map.width)
		if (map.map[map.height - 1][j] != '1')
			wrong = 1;
	if (wrong)
		return (-1);
	return (0);
}
