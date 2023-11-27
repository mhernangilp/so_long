/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:13:35 by mhernang          #+#    #+#             */
/*   Updated: 2023/06/14 13:26:40 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_returns(t_map map)
{
	int	return_value;

	return_value = check_characters(map);
	return_value += check_player(map);
	return_value += check_exit(map);
	return_value += check_coleccionable(map);
	return_value += check_walls(map);
	return_value += check_path(map);
	return (return_value);
}

static void	error_msg(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}

int	check_error(int args, char **argv)
{
	t_map	map;
	int		return_value;

	if (args != 2)
		error_msg("Error\nInvalid number of arguments\n");
	else if (ft_strrncmp(argv[1], ".ber", 4))
		error_msg("Error\nMap file must be .ber!\n");
	map = read_map(argv[1]);
	if (!map.map)
		error_msg("Error\nInvalid map configuration\n");
	return_value = check_returns(map);
	free_map(&map);
	if (return_value != 0)
		error_msg("Error\nInvalid map configuration\n");
	return (return_value);
}
