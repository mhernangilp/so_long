/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:13:35 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/28 13:48:19 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_player(char *map)
{
	int	found;
	int	i;

	i = 0;
	found = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			found += 1;
		i++;
	}
	if (found != 1)
		return (-1);
	return (0);
}

static int	check_exit(char *map)
{
	int	found;
	int	i;

	i = 0;
	found = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			found += 1;
		i++;
	}
	if (found != 1)
		return (-1);
	return (0);
}

static int	check_coleccionable(char *map)
{
	int	found;
	int	i;

	i = 0;
	found = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			found += 1;
		i++;
	}
	if (found == 0)
		return (-1);
	return (0);
}

static int	check_dimensions(char *map)
{
	int	size1;
	int	size2;
	int	i;

	i = 0;
	size1 = 0;
	while (map[i++] != '\n')
		size1++;
	while (map[i])
	{
		size2 = 0;
		while (map[i++] != '\n')
			size2++;
		if (size1 != size2)
			return (-1);
	}
	return (0);
}

static int	check_walls(char *map)
{
	int	i;
	int	wrong;

	i = -1;
	wrong = 0;
	while (map[++i] != '\n')
		if (map[i] != '1')
			wrong = 1;
	while (map[++i])
	{
		if (map[i] != '1')
			wrong = 1;
		while (map[i] != '\n')
			i++;
		if (map[i - 1] != '1')
			wrong = 1;
	}
	if (map[i - 2] != '1')
		wrong = 1;
	if (wrong)
		return (-1);
	return (0);
}

int	check_error(int args, char **argv)
{
	char	*map;
	int		return_value;
	s_map	matrix;

	if (args != 2)
	{
		printf("Error\nInvalid number of arguments");
		return (-1);
	}
	else if (ft_strrncmp(argv[1], ".ber", 4))
	{
		printf("Error\nMap file must be .ber!");
		return (-1);
	}
	map = read_map(argv[1]);
	if (!map)
	{
		printf("Error\nInvalid map configuration");
		return (-1);
	}
	return_value = check_player(map);
	return_value += check_exit(map);
	return_value += check_coleccionable(map);
	return_value += check_dimensions(map);
	return_value += check_walls(map);
	matrix = str_to_mtrx(map);
	printf("'%d', '%d'\n", matrix.width, matrix.height);
	return_value += 0; //check_path(map);
	printf("Return: %d\n", return_value);
	if (return_value != 0)
	{
		printf("Error\nInvalid map configuration");
		return (-1);
	}
	return (return_value);
}
