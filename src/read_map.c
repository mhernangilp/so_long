/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:50:48 by mhernang          #+#    #+#             */
/*   Updated: 2023/06/21 13:12:01 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(1);
	return (fd);
}

static int	getdimensions(char *path, t_map *map)
{
	int		fd;
	char	*temp;
	int		width;
	int		widthaux;
	int		height;

	fd = open_file(path);
	temp = get_next_line(fd);
	if (!temp)
		return (-1);
	width = ft_strlen(temp);
	if (temp[width - 1] == '\n')
		width--;
	widthaux = width;
	height = 1;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (temp)
		{
			width = ft_strlen(temp);
			if (temp[width - 1] == '\n')
				width--;
			if (width != widthaux)
				return (-1);
			widthaux = width;
			height++;
		}
	}
	close(fd);
	free(temp);
	map -> height = height;
	map -> width = width;
	return (0);
}

t_map	read_map(char	*path)
{
	int		fd;
	t_map	map;
	char	*temp;
	int		i;
	int		j;

	if (getdimensions(path, &map) == -1)
	{
		map.map = NULL;
		return (map);
	}
	map.map = malloc(map.height * sizeof(char *));
	i = -1;
	while (++i < map.height)
		map.map[i] = malloc(map.width * sizeof(char *));
	fd = open_file(path);
	temp = get_next_line(fd);
	i = -1;
	while (++i < map.width)
		map.map[0][i] = temp[i];
	j = 0;
	while (++j < map.height)
	{
		free(temp);
		temp = get_next_line(fd);
		i = -1;
		if (temp)
			while (++i < map.width)
				map.map[j][i] = temp[i];
	}	
	close(fd);
	free(temp);
	return (map);
}
