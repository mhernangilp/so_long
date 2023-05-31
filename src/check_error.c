/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:13:35 by mhernang          #+#    #+#             */
/*   Updated: 2023/05/31 17:12:18 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_error(int args, char **argv)
{
	t_map	map;
	int		return_value;

	if (args != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (-1);
	}
	else if (ft_strrncmp(argv[1], ".ber", 4))
	{
		ft_printf("Error\nMap file must be .ber!\n");
		return (-1);
	}
	map = read_map(argv[1]);
	if (!map.map)
	{
		ft_printf("Error\nInvalid map configuration\n");
		return (-1);
	}
	return_value = check_characters(map);
	return_value += check_player(map);
	return_value += check_exit(map);
	return_value += check_coleccionable(map);
	return_value += check_walls(map);
	return_value += check_path(map);
	free_map(&map);
	if (return_value != 0)
	{
		ft_printf("Error\nInvalid map configuration\n");
		return (-1);
	}
	return (return_value);
}
